FROM debian:bullseye

RUN apt-get update -y && \
    apt-get install -y mariadb-server

COPY ./tools/script.sh /tmp/script.sh

RUN  chmod +x /tmp/script.sh

ENTRYPOINT ["bash", "/tmp/script.sh"]

CMD ["mysqld_safe"]