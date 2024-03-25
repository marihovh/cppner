NAME=phonebook
CLANG=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98
SRC=phonebook.cpp
OBJ=$(SRC:%.cpp=%.o)
RM=rm -rf

all : $(NAME) $(OBJ) phonebook.hpp Makefile

%.o:%.cpp
	$(CLANG) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) phonebook.hpp Makefile
	$(CLANG) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
