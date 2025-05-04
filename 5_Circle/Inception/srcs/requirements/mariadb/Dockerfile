FROM debian:bullseye

# 필수 패키지 설치
RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
    mariadb-server \
    procps && \
    rm -rf /var/lib/apt/lists/*

# 소켓 디렉토리 생성 및 권한 설정
RUN mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld

# 설정 파일 복사
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

# 초기화 스크립트 복사
COPY ./util/script.sh /
RUN chmod +x /script.sh

ENTRYPOINT ["/script.sh"]
