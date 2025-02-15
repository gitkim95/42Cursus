C++ = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = ScalarConverter

SOURCES =	main.cpp			\
			ScalarConverter.cpp	
			
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