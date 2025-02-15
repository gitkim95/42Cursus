C++ = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = zombieHorde

SOURCES =	main.cpp		\
			Zombie.cpp		\
			zombieHorde.cpp

OBJS = $(SOURCES:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(C++) $(CPPFLAGS) -o $@ $^

%.o : %.cpp
	$(C++) $(CPPFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re