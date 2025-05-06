#!/bin/sh
FILE=wordpress
cd /var/www/html

WP_CONFIG_PATH="/var/www/html/wordpress/wp-config.php"
WP_ADMIN_PASSWORD="$(cat /run/secrets/wp_admin_password | tr -d '\n')"
WP_USER_PASSWORD="$(cat /run/secrets/wp_user_password | tr -d '\n')"
DB_USER_PASSWORD="$(cat /run/secrets/db_password | tr -d '\n')"
DB_USER="$(cat /run/secrets/db_user | tr -d '\n')"
FTP_PASSWORD="$(cat /run/secrets/ftp_password | tr -d '\n')"


if [ -d "$FILE" ]; then
    echo "$FILE exists."
else
    echo "$FILE not exists." 
    mkdir -p wordpress
    cd wordpress
    
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    php wp-cli.phar --info
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
    wp core download --allow-root 
    
    sleep 10
    wp config create --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_USER_PASSWORD --dbhost=$DB_HOST --allow-root --force
    sleep 10

    # --- Redis 설정 추가 ---
    sed -i "\#/\* That's all, stop editing! Happy publishing\. \*/#i define('WP_REDIS_HOST', '${REDIS_HOST}');\ndefine('WP_REDIS_PORT', '${REDIS_PORT}');\ndefine('WP_REDIS_DATABASE', 0);" wp-config.php
    echo "Redis configuration applied."

    echo "wp-config.php ftp config applied."
    wp core install --url=gitkim.42.fr --title=INCEPTION --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --allow-root  
    wp user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --role=$WP_USER_ROLE --porcelain --allow-root 
    wp theme install neve --activate --allow-root

    # Redis Object Cache 플러그인 설치 및 활성화
    wp plugin install redis-cache --activate --allow-root

    # 모든 플러그인 업데이트
    wp plugin update --all --allow-root

    chown -R www-data:www-data /var/www/html/wordpress/wp-content/uploads

    echo "END" 
fi

exec /usr/sbin/php-fpm7.4 -F
