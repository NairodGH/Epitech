# <p align="center">⏰ Time manager 🏙️ (backend)</p>

## <p align="center">Time tracking app</p>

<p align="center">
  <a href="https://en.wikipedia.org/wiki/Time_management">
  <img src="https://secure.caes.uga.edu/extension/publications/files/html/C1042/images/mceclip03.jpg">
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

[Time manager](https://en.wikipedia.org/wiki/Time_management) is a Msc 1 project where a group of 3 students have to code a time manager app including authentification (login/register/disconnect), a clock-in/clock-out system, a dashboard with graphs, account management, teams, hierarchy roles and more. For the backend development, we had to use [Elixir](https://elixir-lang.org/) with the [Phoenix](https://www.phoenixframework.org/) framework. The whole is containerized with [Docker](https://www.docker.com/).

## 💻 Requirements

- [Docker](https://www.docker.com/)
- [Npm](https://www.npmjs.com/)
- [Node LTS](https://nodejs.org/en/)
- An internet connection (only for npm i)

## 🔧 Building

In \backend:

<ul>

```
docker-compose build
docker-compose up
```

</ul>

In \frontend:

<ul>

Create a *.env* file with the same content as *.env.example*\
Then, as a developer:

<ul>

```
npm i
npm run dev
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
- \config:
  - a directory that holds your project configuration. The config/config.exs file is the entry point for your configuration. At the end of the config/config.exs, it imports environment specific configuration, which can be found in config/dev.exs, config/test.exs, and config/prod.exs. Finally, config/runtime.exs is executed and it is the best place to read secrets and other dynamic configuration.
- \docker:
  - docker entrypoint that setups the database migrations and runs the phoenix server
- \lib:
  - a directory that holds your application source code. This directory is broken into two subdirectories, lib/hello and lib/hello_web. The lib/hello directory will be responsible to host all of your business logic and business domain. It typically interacts directly with the database - it is the "Model" in Model-View-Controller (MVC) architecture. lib/hello_web is responsible for exposing your business domain to the world, in this case, through a web application. It holds both the View and Controller from MVC. We will discuss the contents of these directories with more detail in the next sections.
- \priv:
  - a directory that keeps all resources that are necessary in production but are not directly part of your source code. You typically keep database scripts, translation files, images, and more in here. Generated assets, created from files in the assets directory, are placed in priv/static/assets by default.
- \test:
  - a directory with all of our application tests. It often mirrors the same structure found in lib.
- root files such as:
  - ignore files
  - config files
  - Dockerfile and docker-compose
  - elixir's mix.exs and mix.lock

</ul>

As an user:

<ul>

The backend runs on http://localhost:4000/.

</ul>

## 🤝 Authors

[Dorian AYOUL](https://github.com/NairodGH) • [Pierre HAMEL](https://github.com/pierre1754) • [Pierre MAUGER](https://github.com/PierreMauger)