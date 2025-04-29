FROM debian:bullseye

# 시스템 업데이트 및 Nginx, OpenSSL 설치 후 캐시 정리
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
 && rm -rf /var/lib/apt/lists/*

# Self-signed SSL 인증서 생성 (TLSv1.2/1.3 적용)
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj '/C=FR/ST=Ile-de-France/L=Paris/O=42/OU=42Paris/CN=HYLIM/UID=TTT'

# SSL 스니펫 파일 생성: 인증서와 개인키 경로 지정
RUN echo "ssl_certificate /etc/ssl/certs/nginx-selfsigned.crt;\nssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;" \
    > /etc/nginx/snippets/self-signed.conf

# 보안을 위한 Diffie-Hellman 파라미터 생성
RUN openssl dhparam -out /etc/nginx/dhparam.pem 2048

# 사용자 정의 SSL 파라미터 파일과 사이트 설정 파일들을 복사
COPY ./conf/ssl-params.conf           /etc/nginx/snippets/
COPY ./conf/default                     /etc/nginx/sites-available/
COPY ./conf/static-page.conf            /etc/nginx/sites-available/
COPY ./conf/adminer.conf                /etc/nginx/sites-available/

# 사이트 설정 활성화를 위한 심볼릭 링크 생성
RUN ln -sf /etc/nginx/sites-available/default        /etc/nginx/sites-enabled/default && \
    ln -sf /etc/nginx/sites-available/static-page.conf  /etc/nginx/sites-enabled/static-page.conf && \
    ln -sf /etc/nginx/sites-available/adminer.conf      /etc/nginx/sites-enabled/adminer.conf

EXPOSE 443

# Nginx를 포그라운드에서 실행하여 컨테이너 유지
CMD ["nginx", "-g", "daemon off;"]
