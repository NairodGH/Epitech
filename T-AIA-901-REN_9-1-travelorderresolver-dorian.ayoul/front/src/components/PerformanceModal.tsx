// src/components/PerformanceModal.tsx
import React from 'react';

interface PerformanceModalProps {
    isOpen: boolean;
    onClose: () => void;
}

const PerformanceModal: React.FC<PerformanceModalProps> = ({ isOpen, onClose }) => {
    if (!isOpen) return null;

    return (
        <div className="fixed inset-0 z-50 flex items-center">
            <div className="w-[25%] max-w-[400px] bg-white shadow-lg p-4 h-auto max-h-[80%] overflow-auto">
                <div className="flex justify-between items-center mb-4">
                    <h3 className="text-xl font-semibold">Performance Graphs</h3>
                    <button onClick={onClose} className="text-gray-500 text-xl">&times;</button>
                </div>
                <div className="flex flex-col items-center justify-center space-y-4">
                    <img
                        src="../../src/assets/images/Accuracy.JPG"
                        alt="Accuracy"
                        className="w-full max-h-full object-contain"
                    />
                    <img
                        src="../../src/assets/images/ConfusionMatrix.JPG"
                        alt="Confusion Matrix"
                        className="w-full max-h-full object-contain"
                    />
                </div>
            </div>
        </div>
    );
};

export default PerformanceModal;
