CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SOURCES = 

BSRCS = 

OBJS = $(SOURCES:%.c=%.o)

BOBJS = $(BSRCS:%.c=%.o)

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus: $(BOBJS)
	@if [ ! -f $(NAME) ]; then \
		ar rc $(NAME) $^; \
	else \
		ar r $(NAME) $^; \
	fi
