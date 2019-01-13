CC	=	gcc
CFLAGS = -I/include/ -L./lib/my -lmy -g

SRC_TEST = 	test.c \
			my_strcat.c \
			hidden.c \
			ls_basic.c \
			malloc.c \
			tool_l.c \
		   	lib/my/adresspointer.c \
			lib/my/base.c \
			lib/my/printfunc.c \
			lib/my/printfdeux.c \
			lib/my/printftrois.c \
			lib/my/my_put_nbr.c \
			lib/my/my_put_nbr2.c \
			lib/my/my_putchar.c \
			lib/my/my_putstr.c \
			lib/my/my_putstroctal.c \
			lib/my/my_strlen.c \
			lib/my/my_printf.c
			


OBJ_TEST = $(SRC_TEST:.c=.o)
	
NAME_TEST = unit

NAME	=	bsq

MAIN	= 	main.c

REMOVE	=	remove_space.c

OPERATION	=	operation.c

all:	$(NAME)

$(NAME):
	@make -sC lib/my
	$(CC) $(SRC_TEST) -o my_ls
	


clean:
	rm -f *~ *#

	
fclean: clean
	rm -f $(NAME)

re: fclean all clean