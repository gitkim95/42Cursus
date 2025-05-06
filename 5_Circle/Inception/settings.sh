#!/bin/bash

apt update
apt upgrade -y
apt install sudo
echo 'export PATH=$PATH:/sbin:/usr/sbin:/usr/local/sbin:/bin:/usr/bin:/usr/local/bin:$HOME/bin:$HOME/.local/bin:$HOME/go/bin:$HOME/.cargo/bin' >> ~/.bashrc
source ~/.bashrc
apt install -y ca-certificates curl git make vim docker docker-compose ufw wget filezilla
systemctl start ufw
ufw enable
ufw allow 22/tcp
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome-stable_current_amd64.deb
sudo apt-get install -f
