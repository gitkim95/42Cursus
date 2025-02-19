# Dockerfile for WordPress with PHP-FPM
# PHP-FPM을 사용하여 WordPress를 실행하기 위한 Dockerfile 입니다.
FROM wordpress:php8.0-fpm
# WordPress와 PHP-FPM이 포함된 이미지를 기본 이미지로 사용합니다.

# WordPress 설정 파일 복사
COPY ./wp-config.php /var/www/html/wp-config.php
# 로컬의 wp-config.php 파일을 컨테이너 내부의 WordPress 디렉토리로 복사합니다.

EXPOSE 9000
# 컨테이너 외부에 노출할 포트 9000 (PHP-FPM 기본 포트)을 설정합니다.

CMD ["php-fpm"]
# 컨테이너가 시작될 때 php-fpm 명령어를 실행합니다.
