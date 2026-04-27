NAME 		= cpp03-inheritance
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
RM 			= rm -f
SRC 		=  Animal.cpp Cat.cpp main.cpp
OBJ 		= $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
