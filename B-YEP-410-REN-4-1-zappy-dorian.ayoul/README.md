# Zappy

A game were AIs survive and level up on a map with resources.

## Server

### Build

```

make zappy_server

```

### Run

```

./zappy_server -p <port> -n <team1> <team2> ... -f <frequence> -c <client_by_team> -x <map_width> -y <map_height>

```

## AI

### Build

```

make zappy_ai

```

### Run

```

./zappy_ai -p <port> -n <team_name> -h <ip>

```

## GUI

### Build

```

sudo make graphical

```

### Run

```

./zappy_gui -p <port> -h <machine>

```

## Unit-tests

### Build & Run

```

make unit-tests

```

### Only Run

```

./tests/build/bin/unit-tests

```
