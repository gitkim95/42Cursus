FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y 

RUN mkdir -p /page
COPY ./page/ /page/

COPY ./util/script.sh /

RUN chmod +x script.sh

CMD [ "/script.sh" ]