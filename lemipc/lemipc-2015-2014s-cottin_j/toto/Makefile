
NAME    = lemipc

SRCS    = run.c                 \
          data.c                \
          map.c                 \
          loop.c                \
          semaphore.c           \
          move.c                \
          move2.c

OBJS    = $(SRCS:.c=.o)

CC      = gcc

CFLAGS  = -W -Wall -Werror -Wextra

CD      = cd

CP      = cp -R

MAKE    = make re

AR      = ar r

RM      = rm -rf

#############################
# Complilation Instructions #
#############################

all     : $(NAME)

$(NAME) : $(OBJS)
	$(CD) ./Lib/ && $(MAKE)
	$(CP) ./Lib/libc_my.* ..
	$(CC) -o $(NAME) main.c $(OBJS) -L. -lc_my
	$(CC) -o client_aff aff.c sdl_map.c $(OBJS) -L. -lc_my -lSDL_image -lSDL_ttf `sdl-config --cflags --libs`

clean   :
	$(RM) *.o $(NAME)
	$(CD) ./Lib/ && make clean

re      : clean all
