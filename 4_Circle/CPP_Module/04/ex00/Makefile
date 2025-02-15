C++ = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = Polimorphism

SOURCES =	main.cpp		\
			Animal.cpp		\
			Cat.cpp			\
			Dog.cpp			\
			WrongAnimal.cpp	\
			WrongCat.cpp
			
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