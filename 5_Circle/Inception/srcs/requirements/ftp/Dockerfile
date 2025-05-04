FROM debian:bullseye

RUN apt update -y

RUN apt install vsftpd -y

COPY ./util/script.sh /
RUN chmod +x /script.sh


CMD ["/script.sh"]
