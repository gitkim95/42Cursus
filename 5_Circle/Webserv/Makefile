CC := c++
CFLAGS := -Wall -Wextra -Werror -g -std=c++98
INCLUDE := include
SRC_DIR := src
OBJ_DIR := obj

CLIENT		:=	Client.cpp
CONFIG		:=	Config.cpp	ConfigData.cpp	MetaConfig.cpp
CONTEXT		:=	Context.cpp	Env.cpp
HTTPMESSAGE	:=	Body.cpp	Cookie.cpp	Header.cpp
REQUEST		:=	Request.cpp
RESPONSE	:=	Response.cpp	ResponseGenerator.cpp
SERVER		:=	CGI.cpp		Server.cpp	Session.cpp	Socket.cpp
STATUSCODE	:=	StatusCode.cpp
UTILS		:=	fdUtils.cpp	memUtils.cpp	strUtils.cpp	timeUtils.cpp

SRC_DIRS	:=	client	config	context	httpMessage	request	response	server	statuscode	utils
SRCS :=	$(CLIENT)	$(CONFIG)	$(CONTEXT)	$(HTTPMESSAGE)	$(REQUEST)	$(RESPONSE)	$(SERVER)	\
		$(STATUSCODE)	$(UTILS)	main.cpp

OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:%.cpp=%.o))

vpath %.cpp $(addprefix $(SRC_DIR)/,$(SRC_DIRS)) $(SRC_DIR)

NAME := webserv

.PHONY: clean fclean re all check_dir

all: $(NAME)

check_dir:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp | check_dir
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
