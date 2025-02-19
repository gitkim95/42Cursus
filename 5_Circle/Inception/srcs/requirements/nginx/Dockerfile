# Dockerfile for NGINX
# NGINX를 설치하기 위한 Dockerfile 입니다.
FROM debian:latest
# Debian 최신 버전을 기본 이미지로 사용합니다.

RUN apt-get update && apt-get install -y nginx openssl
# 패키지 목록을 업데이트하고, NGINX와 OpenSSL을 설치합니다.

# SSL 설정
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=US/ST=State/L=City/O=Organization/OU=Unit/CN=${DOMAIN_NAME}"
# 자체 서명된 SSL 인증서를 생성하고, 환경 변수 DOMAIN_NAME을 사용하여 도메인 이름을 설정합니다.

# NGINX 설정 파일 복사
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
# 로컬의 nginx.conf 파일을 컨테이너 내부의 NGINX 설정 디렉토리로 복사합니다.

EXPOSE 443
# 컨테이너 외부에 노출할 포트 443 (HTTPS 기본 포트)을 설정합니다.

CMD ["nginx", "-g", "daemon off;"]
# 컨테이너가 시작될 때 NGINX 서버를 실행합니다.
