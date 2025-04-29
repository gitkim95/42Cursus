# SPECIFIE LA DISTRIBUTION: penultimate 버전의 Debian 사용 (현재 최신이 Bookworm일 경우,Bullseye가 penultimate)
FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y 

RUN apt-get install -y unzip php curl wget php-mysqli php-fpm php-cgi redis php-curl php-gd php-mbstring php-xml php-xmlrpc php-soap php-intl php-zip php-redis
RUN apt-get install -y default-mysql-client

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/
RUN mkdir /run/php

RUN apt-get install -y iputils-ping vim

COPY ./util/* /home/
RUN chmod 777 /home/wpinstall.sh

EXPOSE 9000

ENTRYPOINT ["/home/wpinstall.sh"]
