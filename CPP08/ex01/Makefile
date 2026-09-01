NAME 		= ex01
CPP			= c++
CPPFLAGS	= -g -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf
SRC 		= main.cpp Span.cpp

OBJ_DIR 		= ./obj
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)
$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
