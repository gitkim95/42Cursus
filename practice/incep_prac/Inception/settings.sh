#!/bin/bash

apt update
apt install sudo
echo 'export PATH=$PATH:/sbin:/usr/sbin:/usr/local/sbin:/bin:/usr/bin:/usr/local/bin:$HOME/bin:$HOME/.local/bin:$HOME/go/bin:$HOME/.cargo/bin' >> ~/.bashrc
source ~/.bashrc
apt install ca-certificates curl git make vim docker docker-compose ufw
systemctl start ufw
ufw enable
ufw allow 22/tcp