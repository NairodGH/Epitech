import React from 'react';
import RoadTripMapView from '../components/RoadTripMapView.tsx';

const Map: React.FC = () => {
    const containerStyle = {
        width: '100%',
        height: '100%',
        margin: '0 auto',
        zoomDef: 9,
    };

    return (
        <div className="w-full h-full">
            <RoadTripMapView
                width={containerStyle.width}
                height={containerStyle.height}
                zoomDef={containerStyle.zoomDef}
                margin={containerStyle.margin}
            />
        </div>
    );
};

export default Map;
