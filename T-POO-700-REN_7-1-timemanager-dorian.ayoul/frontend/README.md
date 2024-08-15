# <p align="center">⏰ Time manager 🏙️ (frontend)</p>

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

[Time manager](https://en.wikipedia.org/wiki/Time_management) is a Msc 1 project where a group of 3 students have to code a time manager app including authentification (login/register/disconnect), a clock-in/clock-out system, a dashboard with graphs, account management, teams, hierarchy roles and more. For the frontend development, we chose to use [NextJS](https://nextjs.org/) coupled with [TailwindCSS](https://tailwindcss.com/) for the style and [DevExtreme](https://js.devexpress.com/React/) for the UI components. The whole is containerized with [Docker](https://www.docker.com/).

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
- \docker:
  - docker-entrypoint.sh ran at the start of the docker container
  - docker-healthcheck.sh to ensure the docker container is "healthy" 
- \public:
  - \assets
    - ressources displayed on the app (icons, pictures...)
- \src:
  - \api:
    - \axios:
      - axios instance to use HTTP methods
    - \endpoints:
      - database endpoints with their type and associated asynchronous functions that use axios
  - \app:
    - one folder for each route, if the route uses URL params those are subfolders (example: \employee\\[id]):
      - a page.tsx file exporting a NextJS component (HTML) that will be rendered for the respective route
    - global css rules (import tailwind)
    - layout.tsx, the root HTML file of any browsed page of the app
  - \components:
    - exported NextJS components that are used in the different page.tsx, generally each corresponding to a DevExtreme component
  - \hooks:
    - exported usefull NextJS hooks to make code cleaner
  - \types:
    - exported types
  - \vars:
    - exported constants (to retrieve data from the different DevExtreme forms)
- root files such as:
  - ignore files
  - config files
  - .env
  - Dockerfile and docker-compose
  - npm's package.json and package-lock.json

</ul>

As an user:

<ul>

To access the app, head to http://localhost:3000/. Routes will be described as the part after the last **/** (for example /register is http://localhost:3000/register).

First of all, you'll need to be authenticated to access the app.\
If you do not have an account, you can create one at /register by filling in your first name, last name, email and password (with confirmation).\
If you do have one, just connect with your email and password at /login.\
Accounts have the *employee* role by default, they can be promoted to *manager* by an *admin* or through database, *admin*s are only assigned through database.

Once connected, you'll be redirected to the /dashboard. From there on, each page will have at its top a header. The header has at least 3 buttons:
- settings
- dashboard
- disconnect
If the user is *manager* or *admin*, they'll also have:
- teams
- employees.

The /dashboard is made of a:
- clock-in/clock-out button (to click once when you start working and once when you end it)
- worked hours chart (with the amount of worked hours for each day, and its total average)
- starting/ending hours chart (with the starting and ending hours for each day, and their total average)
- date range bar (allowing you to filter a certain period of days for the charts)

The /settings allows you to edit your account informations, its interface is similar to /register where each field is used to modify the current respective account information except:
- you cannot modify you email
- there is an extra button that allows you to delete your account

The /teams displays a list of the teams, a team has:
- a name
- a manager (account which created it)
- one or multiple members
Each team card will display:
- the name of the team
- the number of members it has
- its manager
You can add a team by clicking on the "Create a team" button and entering its name in the popup.

When clicking on a team card, you'll access /team/:id (where :id is the id of the team you're accessing).\
You'll see the list of the members of the team, each on a card showing their:
- first name
- last name
- role
You can also add a member to the team by clicking the "Add a member" button and selecting the user you want to add.

When clicking on a member card, you'll access /employee/:id (where :id is the id of the member you're accessing).\
An employee's page displays:
- their first name
- their last name
- their email
- their dashboard (except for the clock-in/clock-out part)

If the user has *admin* role, they'll also see:
- a button to promote to *manager* (if *employee*) or demote to *employee* (if *manager*)
- a button to delete the account

Finally, /employees conveniently allows you to see the full list of employees (like /team/:id but for not only for a specific team).

</ul>

## 🤝 Authors

[Dorian AYOUL](https://github.com/NairodGH) • [Pierre HAMEL](https://github.com/pierre1754) • [Pierre MAUGER](https://github.com/PierreMauger)