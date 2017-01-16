##
## Makefile for  in /home/cottin_j/lemipc-2015-2014s-cottin_j
## 
## Made by joffrey cottin
## Login   <cottin_j@epitech.net>
## 
## Started on  Sun Mar 25 17:35:44 2012 joffrey cottin
## Last update Sun Mar 25 17:39:10 2012 joffrey cottin
##

NAME=		lemipc
CFLAGS=		-Wextra -Werror -Wall -W
CC=		gcc

SRC=		main.c\
		execute.c\
		dataz.c\
		battleground.c\
		roll.c\
		semz.c\
		moving_one.c\
		moving_two.c\
		error_func.c

OBJ=		$(SRC:.c=.o)

RM=		rm -f

ECHO=		echo -e

all:		$(NAME)

$(NAME):	$(OBJ)
		-@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
		@$(ECHO) '\033[0;32m> Compiled\033[0m'

clean:
		-@$(RM) ./*.o
		-@$(RM) ./*~
		-@$(RM) ./\#*\#
		@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

fclean:		clean
		-@$(RM) $(NAME)
		@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re:		fclean all