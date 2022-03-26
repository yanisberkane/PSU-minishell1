##
## EPITECH PROJECT, 2021
## Library Makefile
## File description:
## Library compilator and cleaner
##

SRC	=	my_putchar.c \
		my_putstr.c	\
		my_putstr_err.c \
		my_strlen.c \
		my_getnbr.c \
		put_base_nbr.c \
		my_compute_power_rec.c \
		my_strcmp.c \
		my_strncmp.c \
		my_printf.c \
		my_put_uns_nbr.c \
		my_put_capstr.c	\
		my_list.c \
		my_compute_square_root.c \
		my_is_prime.c \
		my_strcat.c \
		my_strncat.c \
		my_strcpy.c \
		my_strncpy.c \
		my_swap.c \
		my_revstr.c \
		my_strupcase.c \
		my_strlowcase.c \
		my_str_isprintable.c \
		my_str_to_word_array.c \
		my_str_arraydup.c

CC 	=	cc

LB	=	libmy.a

OBJ	=	$(SRC:.c=.o)

NAME	=	$(LB)

all:	$(NAME)

$(NAME):
	$(CC) -c -Wall -Wextra $(SRC)
	ar rcs $(NAME) $(OBJ)
	cp libmy.a ../..
	cp my.h ../../include
	cp c_list.h ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../../$(NAME)

re:	fclean all

.PHONY = $(NAME) clean fclean re
