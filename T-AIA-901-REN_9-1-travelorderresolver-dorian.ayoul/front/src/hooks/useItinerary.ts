import { useFetchApi } from './api';
import { useState } from 'react';
import { AudioItineraryResponse } from '../types';

export const useItinerary = () => {
    const [successMessage, setSuccessMessage] = useState<string | null>(null);
    const { isLoading: isTextLoading, error: textError, refetch: fetchTextItinerary, setError: setTextError } = useFetchApi({
        url: 'http://127.0.0.1:8000/text_itinerary',
        method: 'POST',
    });
    const { isLoading: isAudioLoading, error: audioError, refetch: fetchAudioItinerary, setError: setAudioError } = useFetchApi({
        url: 'http://127.0.0.1:8000/audio_itinerary',
        method: 'POST',
    });

    const handleTextSubmit = async (text: string) => {
        try {
            const response = await fetchTextItinerary({ text });
            setSuccessMessage("Text itinerary successfully found!");
            return response;
        } catch (err: any) {
            setTextError({ message: err.message });
            return null;
        }
    };

    const handleAudioSubmit = async (audioFile: Blob): Promise<AudioItineraryResponse | null> => {
        const formData = new FormData();
        formData.append('file', audioFile, 'recorded-audio.wav');
        try {
            const response = await fetchAudioItinerary(formData);
            setSuccessMessage("Audio itinerary successfully found!");
            return response as AudioItineraryResponse;
        } catch (err: any) {
            setAudioError({ message: err.message });
            return null;
        }
    };

    return {
        handleTextSubmit,
        handleAudioSubmit,
        isTextLoading,
        isAudioLoading,
        successMessage,
        setSuccessMessage,
        textError,
        audioError,
        setTextError,
        setAudioError
    };
};
