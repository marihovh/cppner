NAME=unknown
CLANG=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98
SRC=main.cpp Fixed.cpp
OBJ=$(SRC:%.cpp=%.o)
RM=rm -rf

all : $(NAME) $(OBJ) Makefile

%.o:%.cpp
	$(CLANG) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) Makefile
	$(CLANG) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all