##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Program and library compilation
##

SRC	=	src/main.c	\
		src/check_command.c	\
		src/run_prompt.c \
		src/check_bin_path.c \
		src/get_bin_paths.c \
		src/check_directory.c

CFLAGS	=	-Wall -Wextra -I./include -g3

LDFLAGS	=	-L./lib/my -lmy

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make	-C	lib/my/
	make	-C	lib/my_matrix/
	$(CC)	-o	$(NAME)	$(CFLAGS) $(SRC) -g $(LDFLAGS)

clean:
	rm -f	$(OBJ)
	rm -f *~
	rm -f '#'*'#'
	make	-C	lib/my/	clean
	make	-C	lib/my_matrix/ clean

fclean:	clean
	rm	-f	$(NAME)
	make	-C	lib/my/	fclean
	make	-C	lib/my_matrix/ fclean

re:	fclean all

.PHONY = $(NAME) clean fclean re
