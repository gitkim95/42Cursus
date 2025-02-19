#!/bin/bash
# 백업 스크립트 시작

BACKUP_DIR=/home/gitkim/data/mysql-backup
# 백업 파일을 저장할 디렉토리 설정

MYSQL_USER=root
# MySQL 사용자 이름 설정

MYSQL_PASSWORD=${MYSQL_ROOT_PASSWORD}
# MySQL 사용자 비밀번호 설정

MYSQL_DATABASE=${MYSQL_DATABASE}
# 백업할 데이터베이스 이름 설정

mysqldump -u $MYSQL_USER -p$MYSQL_PASSWORD $MYSQL_DATABASE > $BACKUP_DIR/backup.sql
# mysqldump 명령어를 사용하여 데이터베이스 백업을 생성하고, 백업 파일을 지정된 디렉토리에 저장합니다.

echo "Backup completed"
# 백업 완료 메시지를 출력합니다.
