DOCKER_COMPOSE		= docker-compose
DOCKER_COMPOSE_FILE	= ./srcs/docker-compose.yml

DB_PATH				= /home/gitkim/data/db
WP_PATH				= /home/gitkim/data/wordpress

all:
	@mkdir -p $(DB_PATH)
	@mkdir -p $(WP_PATH)
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) up --build -d

init:
	@[ -f ./settings.sh ] && ./settings.sh
	@[ -f ./init_domain.sh ] && ./init_domain.sh
	@mkdir -p $(DB_PATH)
	@mkdir -p $(WP_PATH)

kill:
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) kill

down:
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) down

clean:
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) down -v

fclean: clean
	@rm -rf $(DB_PATH)
	@rm -rf $(WP_PATH)
	@docker system prune -a -f

soft_restart :
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) restart

hard_restart : clean all

re: fclean all

.PHONY: all init kill down clean fclean soft_restart hard_restart re