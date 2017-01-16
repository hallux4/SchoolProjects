HOSTTYPE=	$(shell uname -i)-$(shell uname)

NAME=		libmy_malloc_$(HOSTTYPE).so
LINK=		libmy_malloc.so

SRC=		my_malloc.c malloc_aux.c

OBJ=		$(SRC:.c=.o)


CFLAGS=		-g -c -fPIC   -Wextra -Werror -Wall
LINKFLAGS=	-shared -Wl,-soname,$(LINK) -o $(NAME) -lc
CC=		gcc

RM=		rm -f

ECHO=		echo -e

$(NAME):	$(OBJ)
		$(CC) $(LINKFLAGS) $(OBJ)
		-@ ln -s -f $(NAME) $(LINK)
		@$(ECHO) '\033[0;32m> Compiled\033[0m'

all:		$(NAME)


clean:
		-@$(RM) ./*.o
		-@$(RM) *~
		-@$(RM) ./\#*\#
		@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

fclean:	clean
		-@$(RM) $(NAME)
		@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re:		fclean all

