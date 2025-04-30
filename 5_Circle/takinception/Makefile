
all:
	@mkdir -p /home/gitkim/data/db /home/gitkim/data/wordpress
	@docker-compose -f ./srcs/docker-compose.yml up --build -d

install :
	@apt update 
	@apt upgrade -y
	@apt install docker-compose -y && apt install docker -y && apt install vim -y
	@mkdir -p /home/gitkim/data/db /home/gitkim/data/wordpress
	@./init_domain.sh
	
restart :
	@docker-compose -f ./srcs/docker-compose.yml stop
	@docker-compose -f ./srcs/docker-compose.yml start

down:
	@docker-compose -f ./srcs/docker-compose.yml down

clean:
	@docker rm -f $$(docker ps -qa)
	@docker volume rm -f $$(docker volume ls)
	@rm -rf /home/gitkim/data

re: clean all

# all:
# 	@mkdir -p ${HOME}/data/db ${HOME}/data/wordpress
# 	@docker-compose -f ./srcs/docker-compose.yml up --build -d

# install:
# 	# Homebrew 설치 (이미 설치된 경우 생략 가능)
# 	@if ! command -v brew &> /dev/null; then \
# 		/bin/bash -c "$$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"; \
# 	fi
	
# 	# Docker Desktop 설치
# 	@brew install --cask docker
	
# 	# Docker CLI 및 Compose 플러그인
# 	@brew install docker docker-compose
	
# 	# 디렉토리 생성
# 	@mkdir -p ${HOME}/data/db ${HOME}/data/wordpress
	
# 	# 도메인 설정 스크립트 실행 (수동으로 실행하는 것을 권장)
# 	@echo "다음 명령어를 수동으로 실행하세요:"
# 	@echo "sudo bash ./init_domain.sh"

# restart:
# 	@docker-compose -f ./srcs/docker-compose.yml restart

# down:
# 	@docker-compose -f ./srcs/docker-compose.yml down

# clean:
# 	@docker rm -f $$(docker ps -qa)
# 	@docker volume rm -f $$(docker volume ls -q)
# 	@rm -rf ${HOME}/data

# re: clean all

# -- 아래는 Docker Swarm 관련 명령어들 --

swarm-init:
	@docker swarm init

swarm-join:
	@echo "Swarm 클러스터에 참여하려면 다음 명령어를 사용하세요:"
	@echo "docker swarm join --token <TOKEN> <MANAGER_IP>:2377"

swarm-deploy:
	@docker stack deploy -c ./srcs/docker-compose.yml inception

swarm-remove:
	@docker stack rm inception
	@docker swarm leave --force

.PHONY: all install restart down clean re swarm-init swarm-join swarm-deploy swarm-remove
