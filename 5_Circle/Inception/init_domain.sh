#!/bin/bash

echo "### Enter the server IP ###"
read ip

# 도메인 추가 함수
add_host_entry() {
    local domain=$1

    # 도메인만 포함된 줄을 삭제 (앞뒤 공백 포함)
    echo "Checking for domain: $domain"
    sudo sed -i "/\s*$domain\s*/d" /etc/hosts

    # 도메인 추가
    echo "$ip $domain" | sudo tee -a /etc/hosts > /dev/null
    echo "$domain added with IP $ip"
}

# 도메인들 추가
add_host_entry gitkim.42.fr
add_host_entry adminer.gitkim.42.fr
add_host_entry static.gitkim.42.fr
