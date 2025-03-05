FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    mariadb-server

COPY ./conf/entrypoint.sh /tmp/entrypoint.sh

RUN chmod +x /tmp/entrypoint.sh

ENTRYPOINT ["bash", "/tmp/entrypoint.sh"]