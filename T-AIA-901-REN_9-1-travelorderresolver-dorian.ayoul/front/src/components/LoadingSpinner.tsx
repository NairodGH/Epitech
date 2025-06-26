import React from 'react';

const LoadingSpinner: React.FC = () => (
    <div className="fixed top-4 left-1/2 transform -translate-x-1/2 w-80 bg-gray-700 text-white p-4 rounded-lg shadow-lg flex justify-between items-center z-20">
        <span>Loading...</span>
    </div>
);

export default LoadingSpinner;
