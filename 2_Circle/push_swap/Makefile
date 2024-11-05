CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
MAIN = push_swap.c
SOURCES = ps_greedy_logic.c	\
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
M_OBJS = $(MAIN:.c=.o)
OBJS = $(SOURCES:.c=.o)

BONUS_NAME = checker
B_MAIN = checker.c
B_OBJS = $(B_MAIN:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

all : $(NAME)

$(NAME) : $(M_OBJS) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -g -o $@ $^

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(B_OBJS) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -g -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -g -o $@ -c $<

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -f $(OBJS) $(M_OBJS) $(B_OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus