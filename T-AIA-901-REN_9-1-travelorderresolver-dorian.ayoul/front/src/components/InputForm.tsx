import React, { useState, useCallback } from 'react';
import { FaMicrophone } from 'react-icons/fa';
import { ImSpinner8 } from 'react-icons/im';
import RecordingModal from './RecordingModal';

interface InputFormProps {
    inputText: string;
    setInputText: React.Dispatch<React.SetStateAction<string>>;
    onTextSubmit: () => Promise<void>;
    onAudioSubmit: () => Promise<void>;
    isRecording: boolean;
    isSubmitting: boolean;
}

const InputForm: React.FC<InputFormProps> = ({
                                                 inputText,
                                                 setInputText,
                                                 onTextSubmit,
                                                 onAudioSubmit,
                                                 isRecording,
                                                 isSubmitting,
                                             }) => {
    const [isModalOpen, setIsModalOpen] = useState(false);
    const [activeButton, setActiveButton] = useState<'text' | 'audio' | null>(null);

    const handleTextSubmit = useCallback(async () => {
        setActiveButton('text');
        await onTextSubmit();
        setActiveButton(null);
    }, [onTextSubmit]);

    const handleAudioSubmit = async () => {
        setActiveButton('audio');
        setTimeout(() => setIsModalOpen(true), 0);
        await onAudioSubmit();
        setActiveButton(null);
    };

    const buttonClass = (base: string, hover: string, active: boolean) =>
        `relative text-white p-2 rounded-lg shadow-lg transition duration-300 ease-in-out ${
            active ? 'bg-white text-pink-500' : `${base} hover:${hover}`
        }`;

    const renderOverlay = (isActive: boolean) =>
        isActive && (
            <div className="absolute inset-0 bg-white bg-opacity-50 flex items-center justify-center">
                <ImSpinner8 className="animate-spin text-pink-500" size={20} />
            </div>
        );

    const renderInputField = () => (
        <input
            type="text"
            placeholder="What do you want to do?"
            value={inputText}
            onChange={(e) => setInputText(e.target.value)}
            className="p-2 rounded-lg shadow-lg w-full max-w-md"
            disabled={isSubmitting}
        />
    );

    const renderTextSubmitButton = () => (
        <button
            onClick={handleTextSubmit}
            className={`${buttonClass('bg-pink-500', 'bg-pink-700', activeButton === 'text')}`}
            disabled={isSubmitting}
        >
            Submit
            {renderOverlay(activeButton === 'text')}
        </button>
    );

    const renderAudioSubmitButton = () => (
        <button
            onClick={handleAudioSubmit}
            className={`${buttonClass('bg-blue-500', 'bg-blue-700', activeButton === 'audio')} rounded-full`}
            disabled={isRecording || isSubmitting}
        >
            <FaMicrophone size={20} />
            {renderOverlay(activeButton === 'audio')}
        </button>
    );

    return (
        <div className="absolute top-0 left-0 w-full p-4 z-10 flex justify-center items-center">
            {renderInputField()}
            <div className="ml-2 flex gap-2">
                {renderTextSubmitButton()}
                {renderAudioSubmitButton()}
            </div>

            <RecordingModal
                key={isModalOpen ? 'open' : 'closed'}
                isOpen={isModalOpen}
                duration={5}
                onClose={() => setIsModalOpen(false)}
            />
        </div>
    );
};

export default InputForm;
