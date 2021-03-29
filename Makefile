##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##


SRC		=	main.c											\
			reader.c										\
			scen/default_page.c								\
			time/speed_of_game.c							\
			time/time_to_float.c							\
			draw/heal_bare.c								\
			move/player/move_player.c						\
			move/player/get_player_colition_map.c			\
			animation/player.c								\
			draw/map.c

SRC_COLLISION	=	collision_square.c					\
					collision_circle_square.c				\
					init_hitbox_with_sprite.c				\
					collision_circle.c					\
					debug/display_collision.c				\
					check_if_collision.c

SRC_INIT	=	from_file/get_string_after_c.c						\
				from_file/get_the_int_after_c.c						\
				from_file/get_the_vector_i_after_c.c				\
				from_file/get_sf_int_rect_after_c.c					\
				from_file/get_scene_from_folder.c					\
				from_file/get_sprite_after_c.c						\
				from_file/player/get_inventaire_from_file.c			\
				from_file/player/get_player_from_file.c				\
				from_file/map/get_map_from_file.c					\
				from_file/map/set_info.c							\
				window/init_window.c

SRC_PRE = ./src/

INIT_PRE = ./src/init/

COLLISION_PRE	=	./src/collision/

OBJ     =	$(addprefix $(SRC_PRE), $(SRC:.c=.o)) $(addprefix $(INIT_PRE), $(SRC_INIT:.c=.o))\
			$(addprefix $(COLLISION_PRE), $(SRC_COLLISION:.c=.o))

NAME    =       my_rpg

CFLAGS	=	-l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window -l m \
			-Wall -Wextra -g\
			-I include -I lib/src/include

LFLAGS	=	-L. -lstr -ltools

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
	$(MAKE) -C lib/ clean
	rm -f *.gcno
	rm -f *.gcda
	rm -f ./unit_tests
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) -C lib/ fclean
	rm -f $(NAME)


re:	fclean all

# ------------------------------------------------------------------------ #

# UNITS TESTS PARTS

NAME_CRIT	=	unit_tests

SRC_CRIT	=	tests/src_tests/collision/test_collision_square.c		\
				tests/src_tests/collision/test_collision_circle.c

SRC_FOR_CRIT	=	$(addprefix $(COLLISION_PRE), $(SRC_COLLISION))

T_LDFLAGS	+= -lcriterion

tests_run : $(NAME_CRIT)

$(NAME_CRIT):
	$(CC) -o $(NAME_CRIT) $(SRC_CRIT) $(SRC_FOR_CRIT) $(CFLAGS) $(T_LDFLAGS) --coverage
	./unit_tests

re_crit: fclean tests_run

.PHONY: all clean fclean tests_run re re_crit
