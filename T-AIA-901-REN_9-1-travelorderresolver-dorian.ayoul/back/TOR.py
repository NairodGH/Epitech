
import pandas as pd
import os
from speech_recognition import Recognizer, WavFile, Microphone, RequestError, UnknownValueError
from transformers import pipeline
from sklearn.feature_extraction.text import CountVectorizer, TfidfTransformer
from sklearn.naive_bayes import MultinomialNB
from back.levenshtein import search_match
from langdetect import detect
from fastapi import HTTPException

from back.levenshtein import search_match


ner = pipeline('token-classification', model='CATIE-AQ/NERmembert-large-3entities', tokenizer='CATIE-AQ/NERmembert-large-3entities', aggregation_strategy="simple")
train_data = pd.read_csv("./data/train_data.csv", sep='\t')
supported_cities = pd.read_csv("./data/city_station_association.csv", sep='\t')['city'].tolist()
count_vectorizer = CountVectorizer()
tfidf_transformer = TfidfTransformer()
multinomial_nb = MultinomialNB()


def append_to_csv(transcription, csv_path='./nlp_input.csv') -> str :
    data_frame = pd.read_csv(filepath_or_buffer=csv_path, sep='\t', header=None, names=["sentenceID", "sentence"]) if os.path.exists(csv_path) else pd.DataFrame(columns=["sentenceID", "sentence"])
    new_row = pd.DataFrame([[len(data_frame) + 1, transcription]], columns=["sentenceID", "sentence"])
    data_frame = pd.concat([data_frame, new_row], ignore_index=True)
    data_frame.to_csv(csv_path, sep='\t', header=False, index=False)
    return transcription


def transcribe_audio(wav_path=None) -> str | None:
    recognizer = Recognizer()
    if wav_path:
        with WavFile(wav_path) as source:
            audio = recognizer.record(source)
    else:
        with Microphone() as source:
            recognizer.adjust_for_ambient_noise(source)
            print("Listening...")
            audio = recognizer.listen(source)
    try:
        output = recognizer.recognize_google(audio, language="fr-FR")
        return output
    except UnknownValueError:
        print("Google Speech Recognition could not understand audio")
    except RequestError as e:
        print("Could not request results from Google Speech Recognition service; {0}".format(e))


def get_trip(sentence: str):
    if detect(sentence) not in ['ca', 'fr']:
        print(f"Language detection : {detect(sentence)}")
        raise HTTPException(
                status_code=403,
                detail="Merci d'écrire en Français"
            )

    sentence = sentence.lower()
    print(sentence)
    sentence_cities = [entity['word'] for entity in ner(sentence) if entity['entity_group'] == 'LOC']
    matching_cities = []

    if len(sentence_cities) != 2:
        raise HTTPException(
                status_code=403,
                detail="Merci de renseigner deux villes pour le calcul de l'itinéraire"
            )

    for s in sentence_cities:
        closest_city = search_match(s, supported_cities)
        matching_cities.append(closest_city)

    multinomial_nb.fit(
        tfidf_transformer.fit_transform(
            count_vectorizer.fit_transform(train_data['sentence'])
        )
    , train_data['sentence_type'])
    return matching_cities if multinomial_nb.predict(count_vectorizer.transform([sentence]).toarray())[0] == "from_to" else matching_cities[::-1]


def trip_with_audio(audio_path: str):
    transcription = append_to_csv(transcribe_audio(audio_path))
    trip = get_trip(sentence=transcription)
    return trip, transcription


def trip_with_text(transcription: str):
    transcription = append_to_csv(transcription)
    trip = get_trip(sentence=transcription)
    return trip