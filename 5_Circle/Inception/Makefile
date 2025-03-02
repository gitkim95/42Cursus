DOCKER_COMPOSE_FILE = srcs/docker-compose.yml

DATA_DIR            = /home/gitkim/data
NGINX_DIR           = $(DATA_DIR)/nginx
WORDPRESS_DIR       = $(DATA_DIR)/wordpress
MYSQL_DIR           = $(DATA_DIR)/mysql

.PHONY: up down build restart logs

up: build
	mkdir -p $(NGINX_DIR) $(WORDPRESS_DIR) $(MYSQL_DIR)
	docker-compose -f $(DOCKER_COMPOSE_FILE) up -d

down:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down

build:
	mkdir -p $(NGINX_DIR) $(WORDPRESS_DIR) $(MYSQL_DIR)
	docker-compose -f $(DOCKER_COMPOSE_FILE) up --build -d

restart:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down && docker-compose -f $(DOCKER_COMPOSE_FILE) up -d

logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f
