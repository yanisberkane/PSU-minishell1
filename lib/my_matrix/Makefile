##
## EPITECH PROJECT, 2021
## Matrix library Makefile
## File description:
## Matrix library compilator and cleaner
##

SRC	=	get_sqr_matrix.c \
		get_n_cols_matrix.c

CC 	=	cc

LB	=	libmat.a

OBJ	=	$(SRC:.c=.o)

NAME	=	$(LB)

all:	$(NAME)

$(NAME):
	$(CC) -c -Wall -Wextra $(SRC)
	ar rcs $(NAME) $(OBJ)
	cp libmat.a ../..
	cp my_matrix.h ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../../$(NAME)

re:	fclean all

.PHONY = $(NAME) clean fclean re
