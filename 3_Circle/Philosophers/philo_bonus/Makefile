CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = philo_bonus

SOURCES = 	philo_bonus.c	\
			ph_init_bonus.c	\
			ph_terminator_bonus.c	\
			ph_utils_bonus.c	\
			ph_task_utils_bonus.c	\
			ph_thread_task_bonus.c	\
			ph_handle_sem_bonus.c	\
			ph_check_status_bonus.c
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