CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SOURCES = ft_output.c \
	ft_util.c \
	ft_type_hex.c \
	ft_printf.c \
	ft_type_de_al.c 

OBJS = $(SOURCES:.c=.o)

INCLUDES = ../

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)
	
.c.o :
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
