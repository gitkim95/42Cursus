FROM debian:buster

RUN echo "deb http://deb.debian.org/debian buster main contrib non-free non-free-firmware" > /etc/apt/sources.list && \
    echo "deb http://security.debian.org/debian-security buster/updates main contrib non-free" >> /etc/apt/sources.list && \
    echo "deb http://deb.debian.org/debian buster-updates main contrib non-free" >> /etc/apt/sources.list
RUN apt-get update && apt-get install -y mariadb-server

ARG MYSQL_DATABASE
ARG MYSQL_USER

ENV MYSQL_DATABASE=$MYSQL_DATABASE
ENV MYSQL_USER=$MYSQL_USER

COPY ./conf/init.sql.template /init.sql.template

RUN mkdir -p /docker-entrypoint-initdb.d && \
    envsubst < /init.sql.template > /docker-entrypoint-initdb.d/init.sql

COPY ./conf/my.cnf /etc/mysql/conf.d/my.cnf

COPY ./conf/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["/entrypoint.sh"]
