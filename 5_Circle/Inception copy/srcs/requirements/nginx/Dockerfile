FROM debian:bullseye

RUN apt update; \
    apt install -y nginx openssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \ 
    -keyout /etc/ssl/private/gitkim.key \
    -out /etc/ssl/certs/gitkim.crt \
    -subj="/C=KR/ST=Gyeongsangbuk-do/L=Gyeongsan/O=1337 School/OU=gitkim/CN=gitkim.42.fr"

COPY ./tools/certs.sh /tmp/certs.sh

RUN chmod +x /tmp/certs.sh

COPY ./conf/default /etc/nginx/sites-available/default


ENTRYPOINT ["/tmp/certs.sh"]