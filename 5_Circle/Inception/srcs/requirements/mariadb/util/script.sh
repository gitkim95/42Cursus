#!/bin/sh
DB_USER_PASSWORD="$(cat /run/secrets/db_password | tr -d '\n')"
DB_ROOT_PASSWORD="$(cat /run/secrets/db_root_password | tr -d '\n')"
DB_USER="$(cat /run/secrets/db_user | tr -d '\n')"

service mariadb start 

sleep 5
# CREATE USER #
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_USER_PASSWORD';" | mysql

# PRIVILGES FOR ROOT AND USER FOR ALL IP ADRESS #
echo "GRANT ALL PRIVILEGES ON *.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_USER_PASSWORD';" | mysql
echo "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$DB_ROOT_PASSWORD';" | mysql
echo "FLUSH PRIVILEGES;" | mysql

# CREAT WORDPRESS DATABASE #
echo "CREATE DATABASE IF NOT EXISTS $DB_NAME;" | mysql

kill $(cat /var/run/mysqld/mysqld.pid)

mysqld

