##
## Makefile for  in /home/cottin_j/Bureau/ssh/minishell2-2015ed-2014s-cottin_j
## 
## Made by joffrey cottin
## Login   <joffrey cottin@epitech.net>
## 
## Started on  Mon Dec  5 16:31:12 2011 joffrey cottin
## Last update Fri Dec  9 15:06:07 2011 joffrey cottin
##

#a vous de voir
SRCDIR=		./
DIRDSP=		./
#a vous de voir
OBJDIR=		/home/cottin_j/Bureau/bureau/ssh/minishell2-2015ed-2014s-cottin_j/objets

# source_projet
NAME=		mysh
SRC=		$(wildcard *.c)

# source_lib
LIBDSP=		libdsp.a
SRCDSP=		$(wildcard *.c)

# libmy ou autre
LIB=		-L. -ldsp

# le(s) header(s)
INC        = -I -Iinclude/


OBJ        = $(SRC:.c=.o) $(SRCDSP:.c=.o)
CC        = cc

# optimisation de vitesse
CFLAGS        = -O2 -W -Wall -ansi -pedantic -g

#CHK_SOURCES=	pars_args.c # $(SRC) $(SRCDSP)
RM        = rm -f

# commentaire process
ECHO        = echo -e

all :		$(LIBDSP) $(NAME)

#check-syntax:
#	gcc -o nul -S ${CHK_SOURCES}

$(LIBDSP):      $(OBJ)
	@ar rc $(LIBDSP) $(OBJ)
	@ranlib $(LIBDSP)

$(NAME) :	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@$(ECHO) '\033[0;32m> Compiled\033[0m'

clean :
	-@$(RM) *.o
	-@$(RM) *~
	-@$(RM) \#*#
	@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

fclean :	clean
	-@$(RM) $(NAME)
	@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re :		fclean all

# vrai règle .c.o avec possibilité de choisir repertoire
.c.o: 
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)
