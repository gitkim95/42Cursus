CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = philo

SOURCES = 	philo.c	\
			ph_thread_task.c	\
			ph_init.c	\
			ph_check_status.c	\
			ph_terminator.c	\
			ph_utils.c
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