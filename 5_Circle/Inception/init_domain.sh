#!/bin/bash

echo "### Enter the server IP ###"
read ip;

if grep -q -E "^gitkim.42.fr$" /etc/hosts; then
    echo "gitkim.42.fr exist !"
else
    echo "gitkim.42.fr create "
    echo "$ip gitkim.42.fr" >> /etc/hosts
fi

if grep -q "adminer.gitkim.42.fr" /etc/hosts; then
    echo "adminer.gitkim.42.fr exist !"
else
    echo "adminer.gitkim.42.fr create "
    echo "$ip adminer.gitkim.42.fr" >> /etc/hosts
fi

if grep -q "static.gitkim.42.fr" /etc/hosts; then
    echo "static.gitkim.42.fr exist !"
else
    echo "static.gitkim.42.fr create "
    echo "$ip static.gitkim.42.fr" >> /etc/hosts
fi