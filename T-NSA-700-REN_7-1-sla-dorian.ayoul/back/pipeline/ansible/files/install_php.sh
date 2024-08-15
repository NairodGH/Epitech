#!/bin/sh

sudo apt update
sudo apt upgrade -y

sudo apt install -y apt-transport-https lsb-release ca-certificates wget
wget -O /etc/apt/trusted.gpg.d/php.gpg https://packages.sury.org/php/apt.gpg
echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | sudo tee /etc/apt/sources.list.d/php.list

sudo apt update
sudo apt install -y php7.4 php7.4-mysql php7.4-xml php7.4-mbstring php7.4-fpm zip unzip php7.4-zip
