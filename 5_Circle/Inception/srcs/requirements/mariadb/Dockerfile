FROM debian:bullseye

RUN echo "deb http://deb.debian.org/debian bullseye main contrib non-free" > /etc/apt/sources.list && \
    echo "deb http://security.debian.org/debian-security bullseye-security main contrib non-free" >> /etc/apt/sources.list && \
    echo "deb http://deb.debian.org/debian bullseye-updates main contrib non-free" >> /etc/apt/sources.list

RUN apt-get update && apt-get install -y \
    apt-utils \
    mariadb-server \
    gettext \
    && rm -rf /var/lib/apt/lists/*

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
