CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
MAIN = fdf.c
SOURCES = 
M_OBJS = $(MAIN:.c=.o)
OBJS = $(SOURCES:.c=.o)

MINILIBX_DIR = ./minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

all : $(NAME)

$(NAME) : $(M_OBJS) $(OBJS) $(LIBFT)
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