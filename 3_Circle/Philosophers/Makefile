CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = philo
MAIN = philosophers.c
BONUS =	philo_bonus
SOURCES =
B_SOURCES =
M_OBJS = $(MAIN:.c=.o)
OBJS = $(SOURCES:.c=.o)
B_OBJS = $(B_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(M_OBJS) $(OBJS) $(B_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS) $(M_OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus