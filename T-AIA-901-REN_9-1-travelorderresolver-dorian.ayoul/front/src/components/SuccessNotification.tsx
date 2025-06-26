// SuccessNotification.tsx
import React, { useEffect } from 'react';

interface SuccessNotificationProps {
    message: string;
    onDismiss: () => void;
}

const SuccessNotification: React.FC<SuccessNotificationProps> = ({ message, onDismiss }) => {
    useEffect(() => {
        const timeout = setTimeout(onDismiss, 5000);
        return () => clearTimeout(timeout);
    }, [onDismiss]);

    return (
        <div className="fixed top-4 right-4 bg-green-500 text-white p-4 rounded-lg shadow-lg z-20">
            <span>{message}</span>
            <button className="ml-2" onClick={onDismiss}>×</button>
        </div>
    );
};

export default SuccessNotification;
