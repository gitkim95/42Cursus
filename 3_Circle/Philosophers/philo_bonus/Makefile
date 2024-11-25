CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = philo_bonus

SOURCES = 	philo_bonus.c	\
	asd.c
OBJS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re