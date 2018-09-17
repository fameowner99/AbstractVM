NAME = avm

CC = clang++

FLAGS = -std=c++11 -Wall -Wextra -Werror

RM = rm -f

SRC = src/Lexer.cpp src/main.cpp src/OperandFactory.cpp src/Parser.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ 
	@echo "avm done."

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
