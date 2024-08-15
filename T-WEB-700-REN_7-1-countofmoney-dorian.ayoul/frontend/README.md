# <p align="center">📈 Count of money 🪙 (frontend)</p>

## <p align="center">Keep informed and beat the coins</p>

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

[Count of money](https://en.wikipedia.org/wiki/Cryptocurrency) is a Msc 1 project where a group of 3 students have to code a cryptocurrencies tracking app including anonymous/user/administrator accounts, authentification (login/register/disconnect with email/password or Oauth), cryptocurrencies courses evolution tracking, crypto articles in the press with [RSS](https://en.wikipedia.org/wiki/RSS), preferences settings, administrator management. For the frontend development, we chose to use [NextJS](https://nextjs.org/) coupled with [TailwindCSS](https://tailwindcss.com/) for the style and [Echarts](https://echarts.apache.org/en/index.html) for the UI components. The whole is containerized with [Docker](https://www.docker.com/).

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

Complete *.env*
```
docker compose up
pnpm i
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
- public
  - ressources displayed on the app (icons, pictures...)
- src
  - axios
    - handle HTTP requests for API communication in a Redux-powered application.
  - components
    - code components used by the pages, uses the atomic architecture
  - hooks
    - utils for components
  - pages
    - the site pages rendered on the client by NextJS 12
  - store
    - dynamically store data to prevent callbacks overuse
  - styles
    - css site styling
- root files such as:
  - ignore files
  - config files
  - .env
  - Dockerfile and docker-compose
  - pnpm's package.json and package-lock.json


</ul>

As an user:

<ul>

To access the app, head to http://localhost:3000/. Routes will be described as the part after the last **/** (for example /register is http://localhost:3000/register). / will redirect you to /dashboard.

If you wish to visit the site anonymously, you can just go to /dashboard. You'll have be restricted to the N (defined by an admin) most popular cryptocurrency courses as well as the latest K (defined by an admin) articles in the press.

If you want to browse as an user, you can either register (if you don't have an account, with an email and password or with a google account) or login (if you already have an account, through the same means). On top of consulting the dashboard with N crypto courses and K press articles, you can determine your own list of crypto-currencies to track and your own keywords to refine the press view in /settings.

Finally, as an admin you'll have the same app as listed above but with an extra menu tab that'll lead you to /userdefaults where you can define how many cryptocurrency courses and press articles the dashboard displays.
You'll also be able to choose from lists which cryptos and press sources (RSS feeds) will be shown.

</ul>

## 🤝 Authors

[Dorian AYOUL](https://github.com/NairodGH) • [Pierre HAMEL](https://github.com/pierre1754) • [Pierre MAUGER](https://github.com/PierreMauger)