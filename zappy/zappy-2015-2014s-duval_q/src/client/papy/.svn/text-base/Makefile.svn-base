NAME=		client

CPPFLAGS+=	#-W -Wextra -Werror -Wall
CC=		g++

SRC=		main.cpp\
		client.cpp\
		connect.cpp\
		options.cpp

OBJ=		$(SRC:.cpp=.o)

RM=		rm -f

# commentaire du process
ECHO=		echo -e

all:		$(NAME)
$(NAME):	$(OBJ)
		@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
		@$(ECHO) '\033[0;32m> Compiled\033[0m'

clean:
		-@$(RM) $(OBJ)
		-@$(RM) *~
		-@$(RM) \#*#
		@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

fclean:	clean
		-@$(RM) $(NAME)
		@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re:		fclean all