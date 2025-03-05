DOCKER_COMPOSE		=	docker-compose
DOCKER_COMPOSE_FILE	=	srcs/docker-compose.yml

RM					=	rm -r

DATA_DIR            =	/home/gitkim/data
WORDPRESS_DIR       =	$(DATA_DIR)/wordpress
MYSQL_DIR           =	$(DATA_DIR)/mysql

.PHONY: up down clean fclean restart kill logs

up: 
	mkdir -p $(WORDPRESS_DIR) $(MYSQL_DIR)
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) up --build -d

down:
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) down

clean:
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) down -v

fclean: clean
	@$(RM) $(WORDPRESS_DIR) $(MYSQL_DIR)
	docker system prune -a -f

restart: clean up

kill:
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) kill

logs:
	@$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) logs -f
