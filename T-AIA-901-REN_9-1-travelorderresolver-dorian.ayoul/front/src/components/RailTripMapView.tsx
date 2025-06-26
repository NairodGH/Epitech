import React, { useEffect, useState, useRef } from 'react';
import { GoogleMap, DirectionsRenderer, Marker, InfoWindow } from '@react-google-maps/api';
import { Station } from '../types';

interface RailTripMapViewProps {
    center: google.maps.LatLngLiteral;
    zoom: number;
    stations: Station[];
}

interface RouteInfo {
    stationName: string;
    duration: number;
    distanceInMeters: number;
    isCorrespondance: boolean;
}

interface StationMarker {
    position: google.maps.LatLngLiteral;
    title: string;
    icon: google.maps.Icon;
}


const ROUTE_SEGMENT_COLOR = "#4A90E2";

const RailTripMapView: React.FC<RailTripMapViewProps> = ({ center, zoom, stations }) => {
    const [directions, setDirections] = useState<google.maps.DirectionsResult[]>([]);
    const [stationMarkers, setStationMarkers] = useState<StationMarker[]>([]);
    const [routeInfo, setRouteInfo] = useState<RouteInfo[]>([]);
    const [selectedStation, setSelectedStation] = useState<string | null>(null);
    const [selectedStationPos, setSelectedStationPos] = useState<google.maps.LatLngLiteral | null>(null);
    const [showRouteInfo, setShowRouteInfo] = useState(false);
    const [errorMessage, setErrorMessage] = useState<string | null>(null);

    const mapRef = useRef<google.maps.Map | null>(null);
    const centerRef = useRef(center);
    const zoomRef = useRef(zoom);

    useEffect(() => {
        if (stations.length > 1) {
            createMarkers();
            requestRoutes();
        }
    }, [stations]);


    const createMarkers = async () => {
    const geocoder = new google.maps.Geocoder();
    const markers: StationMarker[] = [];

    for (const [index, station] of stations.entries()) {
        const stationLocation = await geocodeStation(geocoder, station.station_name);
        if (stationLocation) {
            // Define the marker appearance based on the station type
            let icon: google.maps.Icon = {
                path: google.maps.SymbolPath.CIRCLE,
                scale: 5,  // Default size for a red dot
                fillColor: 'green',
                fillOpacity: 1,
                strokeWeight: 1
            };

            // Modify the icon based on the station type
            if (index === 0 || index === stations.length - 1) {
                // Departure or Arrival station: Large yellow circle
                icon = {
                    path: google.maps.SymbolPath.CIRCLE,
                    scale: 10,
                    fillColor: 'yellow',
                    fillOpacity: 1,
                    strokeWeight: 1
                };
            } else if (station.isCorrespondance) {
                // Correspondance station: Smaller purple circle
                icon = {
                    path: google.maps.SymbolPath.CIRCLE,
                    scale: 7,
                    fillColor: 'orange',
                    fillOpacity: 1,
                    strokeWeight: 0
                };
            }

            markers.push({
                position: {
                    lat: stationLocation.lat(),
                    lng: stationLocation.lng()
                },
                title: station.station_name,
                icon  // Set the icon for this marker
            });
        }
    }

    setStationMarkers(markers);
};


    const requestRoutes = async () => {
        const geocoder = new google.maps.Geocoder();
        const allRouteInfos: RouteInfo[] = [];
        setErrorMessage(null);
        setShowRouteInfo(false);
    
        try {
            // Geocode all station names to get their coordinates
            const coordinates = await Promise.all(
                stations.map(station => geocodeStation(geocoder, station.station_name))
            );
    
            const validCoordinates = coordinates.filter((coord): coord is google.maps.LatLng => coord !== null);
    
            if (validCoordinates.length < 2) {
                throw new Error('Not enough valid coordinates to create a route');
            }
    
            // Create directions service
            const directionsService = new google.maps.DirectionsService();
            const waypoints = validCoordinates.slice(1, -1).map(point => ({
                location: point,
                stopover: true
            }));
    
            const result = await new Promise<google.maps.DirectionsResult>((resolve, reject) => {
                directionsService.route(
                    {
                        origin: validCoordinates[0],
                        destination: validCoordinates[validCoordinates.length - 1],
                        waypoints: waypoints,
                        travelMode: google.maps.TravelMode.DRIVING,
                        optimizeWaypoints: false
                    },
                    (result, status) => {
                        if (status === google.maps.DirectionsStatus.OK && result) {
                            resolve(result);
                        } else {
                            reject(status);
                        }
                    }
                );
            });
    
            // Process legs and create route info
            if (result.routes[0] && result.routes[0].legs) {
                result.routes[0].legs.forEach((leg, index) => {
                    const stationName = stations[index] ? stations[index].station_name : `Station ${index + 1}`;
                    const distanceInMeters = leg.distance?.value || 0;
                    const duration = leg.duration?.value || 0;
                    const isCorrespondance = stations[index].isCorrespondance;
    
                    allRouteInfos.push({
                        stationName,
                        duration,
                        distanceInMeters,
                        isCorrespondance
                    });
                });
            }
    
            // Handle the last station separately if not included
            const lastStationName = stations[stations.length - 1]?.station_name || `Station ${stations.length}`;
            const lastLeg = result.routes[0].legs[result.routes[0].legs.length - 1];
            const lastDistanceInMeters = lastLeg.distance?.value || 0;
            const lastDuration = lastLeg.duration?.value || 0;
    
            allRouteInfos.push({
                stationName: lastStationName,
                duration: lastDuration,
                distanceInMeters: lastDistanceInMeters,
                isCorrespondance: stations[stations.length - 1].isCorrespondance
            });
    
            setDirections([result]);  // Save directions
            setRouteInfo(allRouteInfos);  // Save route info
            setShowRouteInfo(true);
    
            const bounds = new google.maps.LatLngBounds();
            validCoordinates.forEach(point => bounds.extend(point));
            mapRef.current?.fitBounds(bounds);
    
        } catch (error) {
            console.error('Failed to get directions:', error);
            setErrorMessage(stations.length > 10
                ? 'Route has more than 10 stations. Showing station markers only.'
                : 'Unable to calculate the route. Showing station markers only.');
        }
    };      

    const geocodeStation = async (geocoder: google.maps.Geocoder, station: string): Promise<google.maps.LatLng | null> => {
        try {
            const result = await new Promise<google.maps.GeocoderResult[]>((resolve, reject) => {
                geocoder.geocode({ address: station }, (results, status) => {
                    if (status === google.maps.GeocoderStatus.OK && results) {
                        resolve(results);
                    } else {
                        reject(status);
                    }
                });
            });

            return result[0].geometry.location;
        } catch (error) {
            console.error(`Geocoding failed for station "${station}":`, error);
            return null;
        }
    };

    return (
        <div className="w-full h-full relative">
            <GoogleMap
                mapContainerStyle={{ width: '100%', height: '100%' }}
                center={centerRef.current}
                zoom={zoomRef.current}
                onLoad={(map) => {
                    mapRef.current = map;
                }}
            >
                {directions.map((direction, index) => (
                    <DirectionsRenderer 
                        key={index}
                        directions={direction}
                        options={{
                            suppressMarkers: true,
                            polylineOptions: {
                                strokeColor: ROUTE_SEGMENT_COLOR,
                                strokeWeight: 4
                            }
                        }}
                    />
                ))}

                {stationMarkers.map((marker, index) => (
                    <Marker
                        key={index}
                        position={marker.position}
                        title={marker.title}
                        icon={marker.icon}  // Apply the custom icon here
                        onClick={() => {
                            setSelectedStation(marker.title);
                            setSelectedStationPos(marker.position);
                        }}
                    />
                ))}


                {selectedStation && selectedStationPos && (
                    <InfoWindow
                        position={selectedStationPos}
                        onCloseClick={() => {
                            setSelectedStation(null);
                            setSelectedStationPos(null);
                        }}
                    >
                        <div className="p-2">
                            <h3 className="font-bold">{selectedStation}</h3>
                        </div>
                    </InfoWindow>
                )}
            </GoogleMap>
            
            {/* Error Toast */}
            {errorMessage && (
                <div className="absolute top-4 right-4 bg-orange-100 border-l-4 border-orange-500 text-orange-700 p-4 rounded shadow-lg">
                    <div className="flex items-center">
                        <div className="w-4 h-4 mr-2">⚠️</div>
                        <p>{errorMessage}</p>
                    </div>
                </div>
            )}

            {/* Route Information Display */}
            {showRouteInfo && routeInfo.length > 0 && (
                <div className="absolute right-4 top-1/2 transform -translate-y-1/2 bg-white p-4 rounded-lg shadow-lg max-h-80 overflow-y-auto w-72">
                    <h3 className="font-bold mb-2">Description de votre trajet :</h3>
                    {routeInfo.slice(0, -1).map((info, index) => {
                        const nextStation = routeInfo[index + 1];
                        return (
                            <div key={index} className="mb-4 pb-2 border-b border-gray-200 last:border-0">
                                <h4>{info.stationName} à {nextStation.stationName}</h4>
                                <p className="text-sm text-gray-600">
                                    Distance : {Math.floor(info.distanceInMeters / 1000)} km
                                </p>
                                <p className="text-sm text-gray-600">
                                    Durée : {Math.floor(info.duration / 60)} minutes
                                </p>
                                {index < routeInfo.length - 2 && (
                                    <p className="text-sm text-gray-600">
                                        Changement de train à l'arrivée : {nextStation.isCorrespondance ? 'Oui' : 'Non'}
                                    </p>
                                )}
                            </div>
                        );
                    })}
                </div>
            )}
        </div>
    );
};

export default RailTripMapView;