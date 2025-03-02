FROM debian:buster

RUN apt-get update && apt-get install -y \
    apt-utils lsb-release ca-certificates apt-transport-https software-properties-common wget curl unzip mariadb-client gnupg\
    && echo "deb https://packages.sury.org/php/ buster main" | tee /etc/apt/sources.list.d/sury-php.list \
    && wget -qO - https://packages.sury.org/php/apt.gpg | apt-key add - \
    && apt-get update

RUN apt-get update && apt-get install -y \
    php8.0-fpm php8.0-mysql php8.0-mbstring php8.0-xml php8.0-curl php8.0-gd php8.0-zip \
    wget unzip curl mariadb-client \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz --strip-components=1 \
    && rm latest.tar.gz

COPY ./wp-config.php /var/www/html/wp-config.php

RUN chown -R www-data:www-data /var/www/html \
    && chmod -R 755 /var/www/html

EXPOSE 9000

CMD ["php-fpm"]
