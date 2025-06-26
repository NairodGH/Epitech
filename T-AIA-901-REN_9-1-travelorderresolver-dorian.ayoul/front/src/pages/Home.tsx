// Home.tsx
import React from 'react';
import { useNavigate } from 'react-router-dom';
import '../assets/styles/Home.css';

const Home: React.FC = () => {
    const navigate = useNavigate();

    return (
        <div> {/* Wrapping element */}
            <div className="home-title-div">
                <h1 className="home-title">Choose your application</h1>
            </div>
            <div className="home-container">
                {/* First Rectangle for SmartEpicTrip */}
                <div
                    className="home-section smart-epic-trip"
                    onClick={() => navigate('/epic-rail-trip')}
                >
                    <h2 className={"home-title-app"}>Epic Rail Trip</h2>
                </div>

                {/* Second Rectangle for EpicRoadTrip */}
                <div
                    className="home-section epic-road-trip"
                    onClick={() => navigate('/epic-road-trip')}
                >
                    <h2 className={"home-title-app"}>Epic Road Trip</h2>
                </div>
            </div>
        </div>
    );
};

export default Home;
