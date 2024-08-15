FROM elixir:1.15.6

RUN mkdir /app
COPY . /app
WORKDIR /app

RUN mix local.hex --force

RUN apt-get update && \
    apt-get install -y inotify-tools && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN mix do deps.get deps.compile, compile
RUN mix phx.digest

RUN mix phx.swagger.generate

ENTRYPOINT [ "./docker/entrypoint.sh" ]
