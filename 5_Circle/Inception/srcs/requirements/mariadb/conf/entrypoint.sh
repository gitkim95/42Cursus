#!/bin/bash
MYSQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
MYSQL_PASSWORD=$(cat /run/secrets/db_password)

envsubst < /init.sql.template | mysql -u root

exec mysqld