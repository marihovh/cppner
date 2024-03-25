NAME=zombie
CLANG=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98
SRC=./Zombie.cpp ./zombieHorde.cpp ./main.cpp
OBJ=$(SRC:%.cpp=%.o)
RM=rm -rf

all : $(NAME) $(OBJ) Zombie.hpp Makefile

%.o:%.cpp Zombie.hpp
	$(CLANG) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) Zombie.hpp Makefile
	$(CLANG) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
