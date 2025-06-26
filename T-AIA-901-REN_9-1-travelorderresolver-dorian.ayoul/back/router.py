import subprocess
from fastapi import APIRouter, HTTPException, UploadFile, File
from pydantic import BaseModel
import os
import time

from back.TOR import trip_with_audio, trip_with_text
from back.path_finder_program import path_finder

router = APIRouter()


class Station(BaseModel):
    station_name: str
    distance: int
    isCorrespondance: bool

class FinderResponse(BaseModel):
    stations: list[Station]
    distance: float | None

class WithAudioTranscription(FinderResponse):
    transcription: str

class TextRequest(BaseModel):
    text: str

def convert_webm_to_wav(input_path: str, output_path: str):
    try:
        subprocess.run(['ffmpeg', '-i', input_path, output_path], check=True)
    except subprocess.CalledProcessError as e:
        raise Exception("Error converting audio format") from e

@router.post("/audio_itinerary", response_model=WithAudioTranscription)
async def find_audio_itinerary(file: UploadFile = File(...)):
    try:
        # Ensure the directory exists
        os.makedirs('temp_audio', exist_ok=True)

        # Create unique filenames with timestamp
        timestamp = int(time.time())
        webm_path = f"temp_audio/{timestamp}_{file.filename}"
        wav_path = f"temp_audio/{timestamp}_{file.filename}.wav"

        with open(webm_path, "wb") as f:
            content = await file.read()
            f.write(content)

        convert_webm_to_wav(webm_path, wav_path)

        cities, transcription = trip_with_audio(wav_path)
        data, distance = path_finder(cities[0], cities[1])
        stations = [
            Station(station_name=station[0], distance= station[2], isCorrespondance=station[3])
            for station in data
        ]
        return WithAudioTranscription(stations=stations, distance=distance, transcription=transcription)

    except HTTPException as e:
        raise e
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
    finally:
        if os.path.exists(webm_path):
            os.remove(webm_path)
        if os.path.exists(wav_path):
            os.remove(wav_path)


@router.post("/text_itinerary", response_model=FinderResponse)
async def find_text_itinerary(text: TextRequest):
    try:
        cities = trip_with_text(text.text)
        data, distance = path_finder(cities[0], cities[1])
        stations = [
            Station(station_name=station[0], distance= station[2], isCorrespondance=station[3])
            for station in data
        ]
        return FinderResponse(stations=stations, distance=distance)
    except HTTPException as e:
        raise e
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))