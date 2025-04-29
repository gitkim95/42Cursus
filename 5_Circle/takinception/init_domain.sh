#!/bin/bash

echo "### Enter the server IP ###"
read ip;

if grep -q -E "^hylim.42.fr$" /etc/hosts; then
    echo "hylim.42.fr exist !"
else
    echo "hylim.42.fr create "
    echo "$ip hylim.42.fr" >> /etc/hosts
fi

if grep -q "adminer.hylim.42.fr" /etc/hosts; then
    echo "adminer.hylim.42.fr exist !"
else
    echo "adminer.hylim.42.fr create "
    echo "$ip adminer.hylim.42.fr" >> /etc/hosts
fi

if grep -q "static.hylim.42.fr" /etc/hosts; then
    echo "static.hylim.42.fr exist !"
else
    echo "static.hylim.42.fr create "
    echo "$ip static.hylim.42.fr" >> /etc/hosts
fi