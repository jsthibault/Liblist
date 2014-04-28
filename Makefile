##
## Makefile for Makefile in /home/js/lib
## 
## Made by thibau_j
## Login   <thibau_j@epitech.net>
## 
## Started on  Mon Apr 28 16:42:29 2014 thibau_j
## Last update Mon Apr 28 16:46:45 2014 thibau_j
##

NAME	= Liblist.a

RM=     rm -f

SRC=    function_list_basics.c \
	function_list_move.c \
	function_list_state.c

ECHO=   echo

LDFLAGS=  -Wall -Wextra -ansi -pedantic

OBJ=    $(SRC:.c=.o)

all:    $(NAME)

$(NAME):        $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@$(ECHO) "\033[0;32m> Liblist.a compiled\033[0m"

clean:
	$(RM) $(OBJ)
	@$(ECHO) "\033[0;31m> Directory cleaned\033[0m"

fclean: clean
	$(RM) $(NAME)
	@$(ECHO) "\033[0;31m> Executable cleaned\033[0m"

joke:
	@$(ECHO) "\033[1;31m>Un jour un programme dit à son env Et ! PATH le chemin !< \033[0m"

re:	fclean all
