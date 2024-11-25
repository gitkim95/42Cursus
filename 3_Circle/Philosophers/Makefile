CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = philo
BONUS = philo_bonus

MAIN_SRC = 	philo.c	\
			ph_thread_task.c	\
			ph_init.c	\
			ph_check_status.c	\
			ph_terminator.c	\
			ph_utils.c

BONUS_SRC =	philo_bonus.c

M_DIR = ./philo
B_DIR = ./philo_bonus

M_OBJS = $(addprefix $(M_DIR)/, $(MAIN_SRC:.c=.o))
B_OBJS = $(addprefix $(B_DIR)/, $(BONUS_SRCS:.c=.o))

all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(M_OBJS)
	$(CC) $(CFLAGS) -I$(M_DIR) -o $@ $^

$(BONUS) : $(B_OBJS)
	$(CC) $(CFLAGS) -I${B_DIR} -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(M_OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re bonus