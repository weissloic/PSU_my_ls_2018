CC	=	gcc
CFLAGS = -I/include/ -L./lib/my -lmy -g

SRC_TEST = 	test.c \
			

OBJ_TEST = $(SRC_TEST:.c=.o)
	
NAME_TEST = unit

NAME	=	bsq

MAIN	= 	main.c

REMOVE	=	remove_space.c

OPERATION	=	operation.c

all:	$(NAME)

$(NAME):
	$(CC) $(SRC_TEST) -o kikou_benji
	


clean:
	rm -f *~ *#

fclean: clean
	rm -f $(NAME)

re: fclean all clean