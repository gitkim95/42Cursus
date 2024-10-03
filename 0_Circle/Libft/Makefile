CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SOURCES = ft_calloc.c \
	ft_strjoin.c \
	ft_putstr_fd.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_split.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_memmove.c \
	ft_striteri.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_putendl_fd.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_strdup.c \
	ft_itoa.c \
	ft_strmapi.c \
	bonus/ft_lstnew.c \
	bonus/ft_lstadd_front.c \
	bonus/ft_lstsize.c \
	bonus/ft_lstlast.c \
	bonus/ft_lstadd_back.c \
	bonus/ft_lstdelone.c \
	bonus/ft_lstclear.c \
	bonus/ft_lstiter.c \
	bonus/ft_lstmap.c

OBJS = $(SOURCES:%.c=%.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
