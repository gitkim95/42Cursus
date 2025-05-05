#!/bin/bash

echo "### Enter the server IP ###"
read ip

add_host_entry() {
    local domain=$1

    # /etc/hosts 안에 이 도메인이 이미 있는지 검사
    if grep -qE "\s${domain}(\s|$)" /etc/hosts; then
        echo "$domain exists!"
    else
        echo "$domain created."
        echo "$ip $domain" | sudo tee -a /etc/hosts > /dev/null
    fi
}

# 추가하고 싶은 도메인들
add_host_entry gitkim.42.fr
add_host_entry adminer.gitkim.42.fr
add_host_entry static.gitkim.42.fr
