#!bin/bash

# 데이터베이스가 실행 중인지 확인하는 함수
check_db() {
  mysqladmin ping -h "${MYSQL_HOST}" --silent
}

# 데이터베이스가 실행될 때까지 대기
until check_db; do
  echo "Waiting for database connection..."
  sleep 2
done

if [ ! -f /var/www/html/wp-config.php ]; then
    wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER \
        --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOST --allow-root  --skip-check

    wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL \
        --allow-root

    wp user create $WP_USER $MY_EMAIL --role=author --user_pass=$WP_PASSWORD --allow-root

 #   wp config  set WP_DEBUG true  --allow-root

    wp config set FORCE_SSL_ADMIN 'false' --allow-root

    wp config  set WP_CACHE 'true' --allow-root

    chmod 777 /var/www/html/wp-content

    # install theme

    wp theme install twentyfifteen

    wp theme activate twentyfifteen

    wp theme update twentyfifteen
fi


/usr/sbin/php-fpm7.4 -F
