##
## Makefile for  in /home/cottin_j//Documents/FN
## 
## Made by joffrey cottin
## Login   <cottin_j@epitech.net>
## 
## Started on  Tue Oct 25 10:40:54 2011 joffrey cottin
## Last update Sun Nov 20 15:01:44 2011 joffrey cottin
##

CLI=	client
FOLD1=	client_folder/

SRC1=	$(FOLD1)clients.c \
	$(FOLD1)maincli.c \
	$(FOLD1)sourcecli1.c \
	$(FOLD1)sourcecli2.c

OBJ1=	$(SRC1:.c=.o)

SERV=	server
FOLD2=	server_folder/

SRC2=	$(FOLD2)servers.c \
	$(FOLD2)sourceserv1.c \
	$(FOLD2)sourceserv2.c

OBJ2=	$(SRC2:.c=.o)

TRASH=	\#* \
        *~ \
        *.o \

all:	$(CLI) $(SERV)

re:     clean all

$(CLI):		$(OBJ1)
	cc -o $(CLI) $(OBJ1) -Wall -ansi -pedantic $(FOLD1)headtalk.h
	mv client $(FOLD1)

$(SERV):	$(OBJ2)	
	cc -o $(SERV) $(OBJ2) -Wall -ansi -pedantic $(FOLD1)headtalk.h
	mv server $(FOLD2)

clean:
	rm  -f $(FOLD1)$(OBJ1)
	rm  -f $(FOLD2)$(OBJ2)
	rm  -f $(FOLD1)$(TRASH)
	rm  -f $(FOLD2)$(TRASH)

fclean: clean
	rm  -f $(FOLD1)$(CLI)
	rm  -f $(FOLD2)$(SERV)
