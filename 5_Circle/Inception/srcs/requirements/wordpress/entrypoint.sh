#!/bin/bash

# 관리자 사용자와 비밀번호를 환경 변수로 설정합니다.
if [ -f /run/secrets/credentials ]; then
  export WORDPRESS_ADMIN_USER=$(cat /run/secrets/credentials | grep 'WORDPRESS_ADMIN_USER' | cut -d'=' -f2)
  export WORDPRESS_ADMIN_PASSWORD=$(cat /run/secrets/credentials | grep 'WORDPRESS_ADMIN_PASSWORD' | cut -d'=' -f2)
fi

# WordPress가 준비될 때까지 기다립니다.
echo "Waiting for the database to be ready..."
until mysql -h"$WORDPRESS_DB_HOST" -u"$WORDPRESS_DB_USER" -p"$WORDPRESS_DB_PASSWORD" -e 'SELECT 1'; do
  sleep 1
done

# php-fpm을 실행합니다.
exec "$@"
