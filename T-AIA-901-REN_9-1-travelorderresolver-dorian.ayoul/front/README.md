# Epic Rail Trip 🚂 + React + TypeScript + Vite 🌍

Welcome to **Epic Rail Trip**—your journey planning app for exploring train routes across the world! 🚆✈️ This template sets up a minimal React + TypeScript project using Vite with Fast Refresh (HMR), optimized for building and testing a real-time rail itinerary. We've also integrated powerful Google Maps APIs and voice recognition for a truly immersive experience! 🗺️🔊

---

## Features ✨

- **Interactive Map** 🌍: Visualize your rail trip routes using Google Maps, complete with real-time directions, markers, and detailed stations.
- **Voice Recognition** 🎤: Submit destinations and actions via speech using audio recognition. Simply press the microphone button, speak your input, and let the app plan your journey!
- **Text Input** 📝: If you prefer typing, submit your rail journey's stations or actions through the intuitive text field.
- **Performance Insights** 📊: Track the performance of the app's AI as it calculates and generates itineraries, with an interactive performance modal showing real-time graphs.
- **Error Handling** ⚠️: Clear error and success messages keep you informed about the app's current state, so you're never in the dark.

---

## Installation 🔧

1. Clone the repository:

    ```bash
    git clone git@github.com:EpitechMscProPromo2025/T-AIA-901-REN_3.git
    ```

2. Navigate to the project directory:

    ```bash
    cd T-AIA-901-REN_3
    cd front
    ```

3. Install dependencies:

    ```bash
    npm install
    ```

4. Run the app:

    ```bash
    npm run dev
    ```

5. Visit the app in your browser at `http://localhost:3000`.

---

## Technical Setup ⚙️

### 🛠️ Vite + React + TypeScript

This project uses **Vite** as the build tool and **React** as the UI library, with **TypeScript** for type safety and developer productivity. Vite provides fast development builds with Hot Module Replacement (HMR) to enhance your experience during development.

### 🗺️ Google Maps API Integration

- The **Google Maps** API powers the **RailTripMapView** component to display interactive maps.
- **Directions Service** is used to calculate routes and render directions based on departure and arrival stations.
- Markers are created dynamically for each station on your journey, allowing you to visualize your trip.

### 🎤 Audio Recognition

- Using the **Audio Recorder** utility, the app listens to your voice and transcribes it into station names or journey requests.
- The **handleAudioSubmit** function processes the audio data and submits it to the app for itinerary generation.

### ⚡ Performance Insights

- The **PerformanceModal** provides real-time feedback on the AI’s performance, displaying graphs and statistics that track its response time and processing efficiency.

---

## Personalizing the Experience 🔑

To better personalize the app, we recommend adding your own **Google Maps API key**. You can easily configure this by setting up an environment variable in a `.env` file:

```bash
VITE_GOOGLE_MAPS_API_KEY=your_google_maps_api_key
```