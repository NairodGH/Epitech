import React, { useEffect, useState } from 'react';

interface RecordingModalProps {
    isOpen: boolean;
    duration: number;
    onClose: () => void;
}

const RecordingModal: React.FC<RecordingModalProps> = ({ isOpen, duration, onClose }) => {
    const [timeRemaining, setTimeRemaining] = useState(duration);
    const [progress, setProgress] = useState(0);

    useEffect(() => {
        if (isOpen) {
            setTimeRemaining(duration);
            setProgress(0);
        }
    }, [isOpen, duration]);

    useEffect(() => {
        if (isOpen) {
            const timerInterval = setInterval(() => {
                setTimeRemaining((prev) => {
                    const newTime = prev - 1;
                    if (newTime <= 0) {
                        clearInterval(timerInterval);
                        onClose();
                    }
                    setProgress(((duration - newTime) / duration) * 100);
                    return newTime;
                });
            }, 1000);

            return () => clearInterval(timerInterval);
        }
    }, [isOpen, duration, onClose]);

    if (!isOpen) return null;

    return (
        <div className="fixed top-0 left-0 w-full h-full bg-purple-500 bg-opacity-10 flex justify-center items-center z-50">
            <div className="bg-purple-200 p-6 rounded-lg w-80 text-center shadow-xl transform transition duration-300 ease-in-out scale-95 hover:scale-100">
                <h2 className="text-xl font-semibold text-purple-700 mb-4">You can start talking!</h2>
                <div className="mb-4">
                    <div className="text-lg font-medium text-purple-700 mb-2">{timeRemaining}s remaining</div>
                    <div className="w-full bg-purple-100 h-2 rounded-lg overflow-hidden">
                        <div
                            className="bg-purple-500 h-full"
                            style={{ width: `${progress}%` }}
                        />
                    </div>
                </div>
                <button
                    onClick={onClose}
                    className="mt-4 bg-purple-600 text-white p-2 rounded-lg hover:bg-purple-700 transition duration-200 ease-in-out"
                >
                    Close
                </button>
            </div>
        </div>
    );
};

export default RecordingModal;
