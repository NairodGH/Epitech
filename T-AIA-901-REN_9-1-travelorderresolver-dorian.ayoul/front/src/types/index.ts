import React from "react";

export interface PlaceApiResResult {
    business_status: string;
    geometry: Geometry;
    icon: string;
    icon_background_color: string;
    icon_mask_base_uri: string;
    name: string;
    opening_hours: OpeningHours;
    photos: Photo[];
    place_id: string;
    plus_code: PlusCode;
    price_level: number;
    rating: number;
    reference: string;
    scope: string;
    types: string[];
    user_ratings_total: number;
    vicinity: string;
}

export interface Error {
  message: string;
}

export interface InputFormProps {
  inputText: string;
  setInputText: React.Dispatch<React.SetStateAction<string>>;
  onTextSubmit: () => void;
  onAudioSubmit: () => void;
  isRecording: boolean;
}

export interface FetchApiResponse {
  data: never;
}

export interface Location {
    lat: number;
    lng: number;
}

export interface Geometry {
    location: Location;
    viewport: Viewport;
  }

export interface Viewport {
    northeast: Location;
    southwest: Location;
  }

export interface OpeningHours {
    open_now: boolean;
    periods: Period[];
    weekday_text: string[];
  }

export interface Period {
    close: Close;
    open: Open;
  }

export interface Close {
    day: number;
    time: string;
  }
  
  interface Open {
    day: number;
  
    time: string;
  }
  
  interface Photo {
    height: number;
    html_attributions: string[];
    photo_reference: string;
    width: number;
  }
  
  interface PlusCode {
    compound_code: string;
    global_code: string;
  }

export interface PlaceApiReqParams {
    radius?: number;
    keyword?: string;
    opennow?: boolean;
    location?: string;
    pagetoken?: string;
    rankby?: "prominence" | "distance"; 
  }

  interface WaypointsDetails {
    name: string
    address_components?: Array<never>
    photos?: Array<never>
    international_phone_number?: string
    rating?: number
    place_id?: string
    event_id?: string
    images?: string
    date?: string
    type: string
    address?: Array<never>
}

  export interface TripDetailsElement {
        content: WaypointsDetails
        place_id?: string
  }

  export interface PlaceDetail {
    address_components: AddressComponents[]
    adr_address: string 
    business_status: string
    current_opening_hours: OpeningHours[]
    editorial_summary: EditorialSummary
    formatted_address: string 
    formatted_phone_number: string 
    geometry: Geometry
    icon: string
    icon_background_color: string 
    icon_mask_base_uri: string 
    international_phone_number: string 
    name: string 
    opening_hours: OpeningHours[]
    photos: Photo[]
    place_id: string 
    rating: number 
    plus_code: PlusCode
    reference: string 
    reviews: Review[]
    types: string[]
    url: string 
    user_ratings_total: number 
    utc_offset: number 
    vicinity: string 
    website: string 
    wheelchair_accessible_entrance: boolean
  }

  interface AddressComponents {
    long_name: string 
    short_name: string
    types: string[]
  }

export interface EditorialSummary {
    language: string 
    overview: string
  }

export interface Review {
    author_name: string 
    author_url: string 
    language: string 
    original_language: string 
    profile_photo_url: string 
    rating: number 
    relative_time_description: string 
    text: string 
    time: number
    translated: boolean
  }

export interface EventDetail {
  id: string
  dates: {
    start: {
      localDate: string 
    }
  }
  images: [
    {
      url: string
    }
  ]
  name: string
  description: string
  _embedded: {
    venues: [
      {
        address: {
          line1: string 
        }
        city: {name: string}
        country: {name: string}
        postalCode: string
        location: {
          latitude: string
          longitude: string
        }
      }
    ]
  }
}

export interface Station {
    station_name: string;
    distance: number;
    isCorrespondance: boolean;
}

export interface AudioItineraryResponse {
    stations: Station[];
    distance: number;
    transcription: string;
}

export interface AudioItineraryRequest {
    file: Blob;
}

