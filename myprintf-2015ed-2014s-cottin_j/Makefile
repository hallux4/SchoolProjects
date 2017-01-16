##
## Makefile for  in /home/cottin_j//Documents/FN
## 
## Made by joffrey cottin
## Login   <cottin_j@epitech.net>
## 
## Started on  Tue Oct 25 10:40:54 2011 joffrey cottin
## Last update Thu Nov 17 12:44:46 2011 joffrey cottin
##

NAME=	libmy.a

BIN=	my_printf

SRC=	my_printf.c \
	parse_space.c \
	print_func.c \
	source1.c \
	source2.c

OBJ=	$(SRC:.c=.o)

TRASH=	./\#* \
        ./*~ \
        ./*.o \
	./toto.txt \
	./test

all:	$(NAME)

re:     clean all

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bin:	
	cc -o $(BIN) main.c $(NAME) -ansi -pedantic

clean:
	rm  -f $(OBJ)
	rm  -f $(TRASH)

fclean: clean
	rm  -f $(NAME)
