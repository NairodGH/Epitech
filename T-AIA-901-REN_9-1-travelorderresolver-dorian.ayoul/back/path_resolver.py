import pandas as pd
import heapq

timetables = pd.read_csv('./data/timetables.csv', sep='	')
mapping = pd.read_csv('./data/city_station_association.csv', sep='	')
station_list = pd.read_csv('./data/liste-des-gares.csv', sep=';')

def load_graph():
    graph = {}
    for index, row in timetables.iterrows():
        town1 = row['TrainStation1']
        town2 = row['TrainStation2']
        distance = row['Duration']
        if town1 not in graph:
            graph[town1] = []
        if town2 not in graph:
            graph[town2] = []
        graph[town1].append((town2, distance, row['TripId']))
        graph[town2].append((town1, distance, row['TripId']))
    return graph


def dijkstra(graph, start, end):
    # Priority queue to store (cost, town) tuples
    queue = [(0, start, None)]
    # Dictionary to store the shortest distance to each town
    distances = {town: float('inf') for town in graph}
    distances[start] = 0
    # Dictionary to store the shortest path to each town
    previous_town = {town: None for town in graph}
    previous_trip = {town: None for town in graph}

    while queue:
        current_distance, current_town, current_trip = heapq.heappop(queue)
        if current_town == end:
            break
        for neighbor, weight, tripId in graph[current_town]:
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                previous_town[neighbor] = current_town
                previous_trip[neighbor] = tripId
                heapq.heappush(queue, (distance, neighbor, tripId))
    # Reconstruct the shortest path
    path = []
    current_town = end
    while previous_town[current_town] is not None:
        trip_changed = previous_trip[current_town] != previous_trip[previous_town[current_town]]
        path.insert(0, (current_town, previous_trip[current_town], distances[current_town] - distances[previous_town[current_town]], trip_changed))
        current_town = previous_town[current_town]
    if path:
        path.insert(0, (start, None, 0, False))
        if path[0][2] == 0 and path[1][2] == 0:
            path = path[2:]
        if path[-1][2] == 0 and path[-2][2] == 0:
            path = path[:-2]
        path[-1] = (path[-1][0], path[-1][1], path[-1][2], False)  # Ensure the last trip change is always false
    return path, distances[end] if distances[end] != float('inf') else None


def get_station(depart, arrive):
    station1 = mapping[mapping['city'] == depart]['station'].values[0]
    station2 = mapping[mapping['city'] == arrive]['station'].values[0]
    graph = load_graph()
    path, distance = dijkstra(graph, station1, station2)
    return path, distance
