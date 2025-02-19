DOCKER_COMPOSE_FILE = srcs/docker-compose.yml

.PHONY: up down build restart logs

up:
    docker compose -f $(DOCKER_COMPOSE_FILE) up -d

down:
    docker compose -f $(DOCKER_COMPOSE_FILE) down

build:
    docker compose -f $(DOCKER_COMPOSE_FILE) up --build -d

restart:
    docker compose -f $(DOCKER_COMPOSE_FILE) down && docker compose -f $(DOCKER_COMPOSE_FILE) up -d

logs:
    docker compose -f $(DOCKER_COMPOSE_FILE) logs -f
