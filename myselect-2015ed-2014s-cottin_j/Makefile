##
## Makefile for  in /home/cottin_j//Documents/FN
## 
## Made by joffrey cottin
## 
## Started on  Tue Oct 25 10:40:54 2011 joffrey cottin
## Last update Wed Nov 23 04:26:34 2011 joffrey cottin
##

NAME=	my_select

SRC=	main.c \
	my_select.c \
	errorselect.c \
	utils1.c \
	utils2.c \
	place_arg.c \
	fillstruct.c \
	source_annexe.c \
	cursors.c

OBJ=	$(SRC:.c=.o)

TRASH=	./\#* \
        ./*~ \
        ./*.o \
	./toto.txt \
	./test

all:	$(NAME)

re:     fclean all

$(NAME): $(OBJ)
	cc -ansi -pedantic  -g -c $(SRC) -Wall #-Wextra -Werror
	cc -o $(NAME) $(OBJ) -lncurses

clean:
	rm  -f $(TRASH)

fclean: clean
	rm  -f $(NAME)
