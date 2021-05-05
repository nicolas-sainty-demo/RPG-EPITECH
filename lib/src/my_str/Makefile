##
## EPITECH PROJECT, 2021
## B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
## File description:
## Makefile
##

SRC	=	src/my_strcat.c					\
		src/my_strcmp.c					\
		src/my_strlen.c 				\
		src/my_tablen.c					\
		src/str_to_int_arry.c			\
		src/str_to_int.c				\
		src/str_to_word_arry.c			\
		src/strdup_int.c				\
		src/free_char_tab.c				\
		src/my_str_is_num.c				\
		src/c_is_in_str.c				\
		src/display_error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libstr.a

CFLAGS	=	-Wall -Wextra -I ../include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../../../

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f ../../../$(NAME)

re: fclean all
