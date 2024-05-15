NAME=buro
CLANG=c++
CFLAGS=-Wall -Werror -Wextra -std=c++98
SRC=main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ=$(SRC:%.cpp=%.o)
RM=rm -rf
YELLOW=\033[0;33m
RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

all : $(NAME) $(OBJ) Makefile

x:
	@make all
	@echo "$(YELLOW)-------------------------------result--------------------------------${NC}"
	@./buro

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