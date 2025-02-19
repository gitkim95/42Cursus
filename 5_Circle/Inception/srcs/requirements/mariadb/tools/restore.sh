#!/bin/bash
# 복원 스크립트 시작

BACKUP_DIR=/home/gitkim/data/mysql-backup
# 백업 파일이 저장된 디렉토리 설정

MYSQL_USER=root
# MySQL 사용자 이름 설정

MYSQL_PASSWORD=${MYSQL_ROOT_PASSWORD}
# MySQL 사용자 비밀번호 설정

MYSQL_DATABASE=${MYSQL_DATABASE}
# 복원할 데이터베이스 이름 설정

mysql -u $MYSQL_USER -p$MYSQL_PASSWORD $MYSQL_DATABASE < $BACKUP_DIR/backup.sql
# mysql 명령어를 사용하여 백업 파일을 데이터베이스로 복원합니다.

echo "Restore completed"
# 복원 완료 메시지를 출력합니다.
