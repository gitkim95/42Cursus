CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = push_swap.c\
		test.c
OBJS = $(SOURCES:.c=.o)
LIBFT = libft.a
LIBFT_DIR = ./libft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) fclean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all
.PHONY : all clean fclean re