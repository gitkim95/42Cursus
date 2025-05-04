FROM debian:bullseye

RUN apt -y update 

COPY ./util/script.sh /

RUN apt install wget -y && apt install php php-mysql  -y

RUN chmod +x /script.sh

CMD ["/script.sh"]

