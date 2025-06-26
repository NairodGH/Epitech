import pandas as pd
import heapq
from collections import defaultdict
from back.path_resolver import get_station


def load_graph(stop_times, stops):
    # Create a dictionary for fast stop_id -> stop_name lookup
    stop_id_to_name = dict(zip(stops['stop_id'], stops['stop_name']))
    # Initialize graph as a defaultdict of dicts
    graph = defaultdict(dict)
    # Extract relevant columns as NumPy arrays for faster access
    stop_times_sorted = stop_times.sort_values(by=['trip_id', 'stop_sequence'])
    trip_ids = stop_times_sorted['trip_id'].values
    stop_ids = stop_times_sorted['stop_id'].values
    departure_times = stop_times_sorted['departure_time'].values
    arrival_times = stop_times_sorted['arrival_time'].values
    # Iterate over the sorted stop_times array
    for i in range(len(trip_ids) - 1):
        # If the next stop is from the same trip
        if trip_ids[i] == trip_ids[i + 1]:
            stop1_id = stop_ids[i]
            stop2_id = stop_ids[i + 1]
            # Calculate time difference between consecutive stops
            duration = calculate_duration(departure_times[i], arrival_times[i + 1])
            # Lookup stop names
            stop1_name = stop_id_to_name[stop1_id]
            stop2_name = stop_id_to_name[stop2_id]
            if not isinstance(stop1_name, str) or not isinstance(stop2_name, str):
                continue
            if stop2_name not in graph[stop1_name] or duration < graph[stop1_name][stop2_name]:
                graph[stop1_name][stop2_name] = duration
            if stop1_name not in graph[stop2_name] or duration < graph[stop2_name][stop1_name]:
                graph[stop2_name][stop1_name] = duration
    return {stop: list(neighbors.items()) for stop, neighbors in graph.items()}


def calculate_duration(dep_time, arr_time):
    # Convert time to minutes and calculate difference
    dep_h, dep_m, dep_s = map(int, dep_time.split(":"))
    arr_h, arr_m, arr_s = map(int, arr_time.split(":"))
    dep_total = dep_h * 60 + dep_m
    arr_total = arr_h * 60 + arr_m
    return arr_total - dep_total


def path_finder(departure, arrival):
    stop_times = pd.read_csv('./data/stop_times.csv', sep='	')
    stops = pd.read_csv('./data/stops.csv', sep='	')
    graph = load_graph(stop_times, stops)
    stations, distance = get_station(departure, arrival)
    return stations, distance
