CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SOURCES = ft_output.c \
	ft_util.c \
	ft_type_hex.c \
	ft_printf.c \
	ft_type_de_al.c 

OBJS = $(SOURCES:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) $@
	ar rcs $@ $^

$(LIBFT) :
	make -C $(LIBFT_DIR)

.c.o :
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean :
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all