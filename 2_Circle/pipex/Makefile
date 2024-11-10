CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = pipex
MAIN = pipex.c
SOURCES = free_struct.c
M_OBJS = $(MAIN:.c=.o)
OBJS = $(SOURCES:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

all : $(NAME)

$(NAME) : $(M_OBJS) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -f $(OBJS) $(M_OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus