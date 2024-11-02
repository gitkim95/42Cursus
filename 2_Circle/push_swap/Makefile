CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = ps_task_func.c \
	ps_task_parsing.c \
	ps_arrange_arg_1.c \
	ps_arrange_arg_2.c \
	ps_list_utils.c \
	ps_logic_utils.c \
	ps_verification.c \
	push_swap.c
OBJS = $(SOURCES:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -g -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all
.PHONY : all clean fclean re