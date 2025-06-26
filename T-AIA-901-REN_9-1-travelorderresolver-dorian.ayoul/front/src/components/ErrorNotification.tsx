import React, { useEffect } from 'react';

interface ErrorNotificationProps {
    message: string;
    onDismiss: () => void;
}

const ErrorNotification: React.FC<ErrorNotificationProps> = ({ message, onDismiss }) => {
    useEffect(() => {
        const timer = setTimeout(onDismiss, 5000);

        return () => clearTimeout(timer);
    }, [onDismiss]);

    return (
        <div className="fixed top-4 right-4 w-80 bg-red-500 text-white p-4 rounded-lg shadow-lg flex justify-between items-center z-50 transition-all ease-in-out">
            <span className="text-sm font-medium">{message}</span>
            <button className="text-white" onClick={onDismiss}>
                &times;
            </button>
        </div>
    );
};

export default ErrorNotification;
