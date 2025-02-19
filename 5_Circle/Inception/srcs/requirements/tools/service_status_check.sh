#!/bin/bash
# 서비스 상태 확인 스크립트

echo "Checking service status..."

# MariaDB 상태 확인
if systemctl is-active --quiet mariadb; then
    echo "MariaDB is running."
else
    echo "MariaDB is not running."
fi

# NGINX 상태 확인
if systemctl is-active --quiet nginx; then
    echo "NGINX is running."
else
    echo "NGINX is not running."
fi

# WordPress 상태 확인 (예: 웹 서버 상태 확인)
if curl -s --head --request GET http://localhost | grep "200 OK" > /dev/null; then
    echo "WordPress is running."
else
    echo "WordPress is not running."
fi

echo "Service status check completed."
