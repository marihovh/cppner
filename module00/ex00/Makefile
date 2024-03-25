NAME=megaphone
CLANG=c++
CFLAGS=-Wall -Werror -Wextra
SRC=megaphone.cpp
OBJ=$(SRC:%.cpp=%.o)
RM=rm -rf

all : $(NAME) $(OBJ) Makefile

%.o:%.c
	$(CLANG) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CLANG) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all