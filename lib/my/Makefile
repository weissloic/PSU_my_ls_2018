##
## EPITECH PROJECT, 2018
## Makefile
## File description:
CC	=	gcc

SRC	=	adresspointer.c \
		base.c \
		printfunc.c \
		printfdeux.c \
		printftrois.c \
		my_strcpy.c \
		my_put_nbr.c \
		my_put_nbr2.c \
		my_putchar.c \
		my_putstr.c \
		my_putstroctal.c \
		my_strlen.c \
		my_printf.c


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	 $(NAME)

$(NAME):  $(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f *.o
	cp $(NAME) ../../

clean:
	rm -f *~ *# *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all clean

