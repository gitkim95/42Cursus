#!/bin/bash

echo "### Enter the server IP ###"
read ip

add_host_entry() {
    local domain=$1

    # 기존 줄에서 해당 도메인이 포함된 줄을 삭제 (정확히 포함된 줄만)
    sudo sed -i "/[[:space:]]\+$domain\([[:space:]]\+\|$\)/d" /etc/hosts

    # 도메인 추가
    echo "$ip $domain" | sudo tee -a /etc/hosts > /dev/null
    echo "$domain added with IP $ip"
}

# 도메인들 추가
add_host_entry gitkim.42.fr
add_host_entry adminer.gitkim.42.fr
add_host_entry static.gitkim.42.fr
