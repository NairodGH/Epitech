# <p align="center">📈 Crypto Viz 🪙 (backend)</p>

## <p align="center">Real-time crypto currencies tool</p>

<p align="center">
  <a href="https://en.wikipedia.org/wiki/Cryptocurrency">
  <img src="https://bs-uploads.toptal.io/blackfish-uploads/components/blog_post_page/content/cover_image_file/cover_image/1303387/regular_1708x683_Untitled-e7fde53f1e5631a8728cc9aefc1538e8.png">
</p>

## 📋 Table of Contents
<details>
<summary>Click to reveal</summary>

- [About](#-about)
- [Requirements](#-requirements)
- [Building](#-building)
- [Usage](#-usage)
- [Authors](#-authors)

</details>

## 🔍 About

[Crypto Viz](https://en.wikipedia.org/wiki/Cryptocurrency) is a Msc 2 project where a group of 5 students have to code a cryptocurrencies tracking web app including an always running online [web scrapper](https://en.wikipedia.org/wiki/Web_scraping) (cryptocurrency news feed) and analytics buider (process data) that both follow the [consumer/producer paradigm](https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem). For the backend development, we chose to use [NestJS](https://nestjs.com/) and [Prisma](https://www.prisma.io/). The whole is containerized with [Docker](https://www.docker.com/).\
As we based it on the similar Msc 1 project Count of money, we also provide anonymous/user/administrator accounts, authentification (login/register/disconnect with email/password or Oauth), cryptocurrencies courses evolution tracking, crypto articles in the press with [RSS](https://en.wikipedia.org/wiki/RSS), preferences settings and administrator management.

## 💻 Requirements

- [Docker](https://www.docker.com/)
- [Npm](https://www.npmjs.com/) -> [pnpm](https://pnpm.io/)
- [Node LTS](https://nodejs.org/en/)
- An internet connection

## 🔧 Building

In \backend:

<ul>

As prod:

<ul>

Complete *.env.prod*
```
docker compose -f docker-compose.prod.yml build
docker compose -f docker-compose.prod.yml up
```

</ul>

As dev:

<ul>

Create a *.env* file with the same content as *.env.example*\
```
docker compose up
pnpm i
npx prisma generate
npx prisma migrate dev
pnpm start
```

</ul>

</ul>

In \frontend:

<ul>

Create a *.env* file with the same content as *.env.example*\
Then, as a developer:

<ul>

```
pnpm i
pnpm dev
```

</ul>

or as an user:

<ul>

```
docker-compose build
docker-compose up
```

</ul>

</ul>

## 🎮 Usage

As a developer:

<ul>

The file architecture is as follows:
- docker
  - docker-entrypoint.sh ran at the start of the docker container
  - docker-healthcheck.sh to ensure the docker container is "healthy"
- prisma
  - database workflow with migrations and schemas
- src
  - cryptos
    - cryptos related DTOs, controller, module and service
  - feed
    - rss feeds related controller, module and service
  - services
    - coinmarket
      - module and service for the coinmarket API
  - users
    - user management related DTOs, controller, module and service
  - app controller, module and service as well as the backend and prisma's mains
- test
  - backend testing with [Jest](https://jestjs.io/)
- root files such as:
  - ignore files
  - config files
  - .env.prod
  - Dockerfile and docker-compose
  - pnpm's package.json and package-lock.json


</ul>

As an user:

<ul>

The backend runs on http://localhost:4000/.

</ul>

## 🤝 Authors

[Dorian AYOUL](https://github.com/NairodGH) • [Pierre HAMEL](https://github.com/pierre1754) • [Pierre MAUGER](https://github.com/PierreMauger) • [François PARMENTIER](https://github.com/WebDesignPastor) • [Baptiste Lemonnier](https://github.com/Baptill)