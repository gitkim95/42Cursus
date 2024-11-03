CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = push_swap.c	\
	ps_greedy_logic.c	\
	ps_greedy_utils_1.c	\
	ps_greedy_utils_2.c	\
	ps_sort_ac_under_3.c	\
	ps_arrange_arg_1.c	\
	ps_arrange_arg_2.c	\
	ps_task_func.c	\
	ps_task_parsing.c	\
	ps_list_utils.c	\
	ps_logic_utils.c	\
	ps_verification.c
OBJS = $(SOURCES:.c=.o)

BONUS_NAME = checker
B_SOURCES = 
B_OBJS = $(B_SOURCES:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
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
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(OBJS) $(BOBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : all clean fclean re bonus