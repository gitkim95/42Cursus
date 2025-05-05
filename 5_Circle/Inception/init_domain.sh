#!/bin/bash

# IP를 자동으로 설정 (127.0.0.1 또는 VM의 IP로 변경 가능)
ip="127.0.0.1"  # 기본 IP, 필요시 다른 IP로 변경 가능

# 도메인 추가 함수
add_host_entry() {
    local domain=$1

    # 기존에 도메인만 있는 줄을 삭제 (IP와 연결된 줄은 유지)
    echo "Checking for domain: $domain"
    sudo sed -i "/^[[:space:]]*[^[:space:]]\+\s\+$domain[[:space:]]*$/d" /etc/hosts

    # 도메인 추가
    echo "$ip $domain" | sudo tee -a /etc/hosts > /dev/null
    echo "$domain added with IP $ip"
}

# 도메인들 추가
add_host_entry gitkim.42.fr
add_host_entry adminer.gitkim.42.fr
add_host_entry static.gitkim.42.fr
