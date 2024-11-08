CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = fdf
MAIN = fdf.c
SOURCES = fdf_init_struct.c \
	fdf_parse_file.c \
	fdf_set_map_1.c \
	fdf_set_map_2.c \
	fdf_terminator.c \
	fdf_utils.c \
	fdf_valid_file.c
M_OBJS = $(MAIN:.c=.o)
OBJS = $(SOURCES:.c=.o)

MINILIBX_DIR = ./minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

all : $(NAME)

$(NAME) : $(M_OBJS) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(MINILIBX_DIR) -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

%.o : %.c
	$(CC) $(CFLAGS) -I$(MINILIBX_DIR) -O3 -c $< -o $@

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