import React, { useState } from 'react';
import { LoadScript } from '@react-google-maps/api';
import RailTripMapView from '../components/RailTripMapView';
import InputForm from '../components/InputForm';
import LoadingSpinner from '../components/LoadingSpinner';
import ErrorNotification from '../components/ErrorNotification';
import SuccessNotification from '../components/SuccessNotification';
import PerformanceModal from '../components/PerformanceModal';
import { useItinerary } from '../hooks/useItinerary';
import { startRecording } from '../utils/audioRecorder';
import { Station } from '../types';

const EpicRailTripHome: React.FC = () => {
    const {
        handleTextSubmit,
        handleAudioSubmit,
        isTextLoading,
        isAudioLoading,
        successMessage,
        setSuccessMessage,
        textError,
        audioError,
        setTextError,
        setAudioError,
    } = useItinerary();

    const [inputText, setInputText] = useState('');
    const [isRecording, setIsRecording] = useState(false);
    const [isModalOpen, setIsModalOpen] = useState(false);
    const [stations, setStations] = useState<Station[]>([]);

    const handleAudioRecording = async () => {
        setIsRecording(true);
        try {
            const audioBlob = await startRecording();
            const response = await handleAudioSubmit(audioBlob);
            if (response) {
                setStations(response.stations);
                setInputText(response.transcription);
                
            }
        } finally {
            setIsRecording(false);
        }
    };

    const handleTextSubmitWithStations = async () => {
        const response = await handleTextSubmit(inputText);
        if (response?.stations) setStations(response.stations);
    };

    const toggleModal = () => setIsModalOpen((prev) => !prev);

    const modalButtonText = isModalOpen
        ? 'Hide performance graphs'
        : 'Observe our AI\'s performance';

    const NotificationWrapper = () => (
        <>
            {(textError || audioError) && (
                <ErrorNotification
                    message={textError?.message || audioError?.message || "An error occurred"}
                    onDismiss={() => {
                        setTextError(null);
                        setAudioError(null);
                    }}
                />
            )}
            {successMessage && (
                <SuccessNotification
                    message={successMessage}
                    onDismiss={() => setSuccessMessage(null)}
                />
            )}
        </>
    );  

    return (
        <LoadScript googleMapsApiKey={import.meta.env.VITE_GOOGLE_MAPS_API_KEY}>
            <div className="relative h-screen w-screen">
                <RailTripMapView
                    center={{ lat: 46.9044, lng: 2.5064 }}
                    zoom={7}
                    stations={stations}
                />

                <InputForm
                    inputText={inputText}
                    setInputText={setInputText}
                    onTextSubmit={handleTextSubmitWithStations}
                    onAudioSubmit={handleAudioRecording}
                    isRecording={isRecording}
                    isSubmitting={isTextLoading || isAudioLoading}
                />

                {(isTextLoading || isAudioLoading) && <LoadingSpinner />}
                <NotificationWrapper />

                <div className="absolute bottom-0 left-0 p-4 z-10">
                    <button
                        onClick={toggleModal}
                        className={`text-white p-3 rounded-lg transition duration-300 ease-in-out ${
                            isModalOpen ? 'bg-red-500' : 'bg-orange-500'
                        }`}
                    >
                        {modalButtonText}
                    </button>
                </div>

                <PerformanceModal isOpen={isModalOpen} onClose={toggleModal} />
            </div>
        </LoadScript>
    );
};

export default EpicRailTripHome;
