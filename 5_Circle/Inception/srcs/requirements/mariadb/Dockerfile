# Dockerfile for MariaDB
# MariaDB를 설치하기 위한 Dockerfile 입니다.
FROM debian:latest
# Debian 최신 버전을 기본 이미지로 사용합니다.

RUN apt-get update && apt-get install -y mariadb-server
# 패키지 목록을 업데이트하고, MariaDB 서버를 설치합니다.

# 환경 변수 설정
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD
# Dockerfile에서 사용할 빌드 시 환경 변수를 정의합니다.

# 템플릿 파일을 실제 init.sql 파일로 변환
COPY ./conf/init.sql.template /init.sql.template
# 로컬의 init.sql.template 파일을 컨테이너 내부로 복사합니다.
RUN envsubst < /init.sql.template > /docker-entrypoint-initdb.d/init.sql
# 환경 변수를 대체하여 init.sql 파일을 생성합니다.

# MariaDB 설정 파일 복사
COPY ./conf/my.cnf /etc/mysql/conf.d/my.cnf
# 로컬의 my.cnf 파일을 컨테이너 내부의 MariaDB 설정 디렉토리로 복사합니다.

EXPOSE 3306
# 컨테이너 외부에 노출할 포트 3306 (MariaDB 기본 포트)을 설정합니다.

CMD ["mysqld"]
# 컨테이너가 시작될 때 mysqld (MariaDB 서버) 명령어를 실행합니다.
