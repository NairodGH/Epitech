# <p align="center">🅰️ SLA 💻</p>

## <p align="center">Fast and continuous</p>

<p align="center">
  <a href="https://agilefirst.io/agile-devops/">
  <img src="https://agilefirst.io/content/images/2022/06/agile-devops.png">
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

[SLA](https://agilefirst.io/agile-devops/) is a Msc 1 project where a group of 3-5 students, given a [Laravel](https://laravel.com/) (backend)-[Angular](https://angular.io/) (frontend) application, have to configure:
- 3 blank [Debian](https://www.debian.org/) servers (for database, frontend and backend)
- [Ansible](https://www.ansible.com/) recipes to prepare the infrastructure layer and configure those machines
- pipelines for the frontend and backend that must contain:
  - a build step containing the build of the application and creating an artifact containing all the dependencies necessary for running this application into production
  - a test step running the unit tests
  - a deploy step executing an Ansible Playbook
- using those pipelines, a [Gitlab](https://about.gitlab.com/) server for [CI/CD](https://en.wikipedia.org/wiki/CI/CD):
  - CI: build, test and package your applications on Gitlab
  - CD: launch the deployment of each application with Ansible, from Gitlab
- for each of these applications, an Ansible role to deploy it
- an online registry from which to download the app, in this case we use [Nexus](https://www.sonatype.com/products/sonatype-nexus-repository) 3

## 💻 Requirements

- An internet connection
- [Docker](https://www.docker.com/)
- [Git](https://git-scm.com/)
- [ansible-playbook](https://docs.ansible.com/ansible/latest/playbook_guide/playbooks_intro.html)

## 🔧 Building

Docker:

<ul>

Go into the 3 Dockerfiles and change the passwords.

Run
```
docker compose up --build
```

This should create the 3 containers with empty Debians (just with open-ssh, sudo, and python3 to run Ansible on).

Test each container to see if the configuration is properly done with:
```
ssh dbuser@127.0.0.1 -p 2224
python3 --version
```

</ul>


Ansible:

<ul>

Ansible Setup:

<ul>

- Ansible Vault\
    First, locally create a secrets.yml file with ansible-vault.\
    Enter the command:
    ```
    ansible-vault create secrets.yml
    ```
    Then write the SSH password for your containers:
    ```
    ssh_password: example
    ```
    This secrets.yml file should be located in the Playbooks folder alongside other playbooks.
- Run a playbook\
    To run a playbook, for example:
    ```
    ansible-playbook -i inventory.ini playbooks/setup-database.yml --ask-vault-pass
    ```
    The --ask-vault-pass command will prompt for the vault password to access the secret.

</ul>

Database:

<ul>

Run:
```
ansible-playbook -i inventory.ini playbooks/setup-database.yml --ask-vault-pass
```
To check the proper setup of MySQL via Ansible:
- Enter the container
```
ssh dbuser@127.0.0.1 -p 2224
```
- Check the MySQL status
```
sudo systemctl status mysql
```

</ul>

Nginx:

<ul>

To test the proper installation of Nginx:
```
ssh frontenduser@127.0.0.1 -p 2222
nginx -v
```

</ul>

</ul>

## 🎮 Usage

The file architecture is as follows:
- back\
  - .gitlab-ci.yml pipeline to test the backend's install/test/package stages
  - package.sh generates the build's .tar.gz, through some exclusions, for the pipeline's package stage
- docker\
  - docker-compose configuring the services and volumes of the 3 debian docker servers based on their dockerfiles in:
  - backend\
  - database\
  - frontend\

- front\
  - .gitlab-ci.yml pipeline to test the frontend's install/build/test/package stages
- gitlab_instance\
  - docker-compose configuring/starting the gitlab instance that runs on it
  - gitlab nginx instance of the server where the CI/CD is going to be ran
- gitlab_runner\
  - shell commands to run the gitlab instance
- my_ansible_project\
  - playbooks\
    - .gitignore of the local secrets.yml for security
    - setup/deploy playbooks (scripts) for the appropriate application components
  - roles\
    - main.yml for each of the application components that install tasks
- nexus\
  - docker-compose configuring/starting the nexus instance that runs on it
  - nexus nginx instance where the app can be downloaded from
- root files such as:
  - gitignore of miscellaneous things that we don't want to push on github

## 🤝 Authors

[Pierre HAMEL](https://github.com/pierre1754) • [François PARMENTIER](https://github.com/WebDesignPastor) • [Pierre MAUGER](https://github.com/PierreMauger) • [Dorian AYOUL](https://github.com/NairodGH)
