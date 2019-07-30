##
## EPITECH PROJECT, 2018
## makefile
## File description:
## By DavidS
##

NAME_LAR	= largeur/solver

NAME_PRO	= profondeur/solver

NAME_A		= astar/solver

NAME_TOUR	= tournoi/solver

NAME_GEN	= generateur/generateur

SRCS_LAR	= sources/largeur/main.c\
		  sources/largeur/map.c\
		  sources/largeur/largeur.c

SRCS_PRO	= sources/profondeur/main.c\
		  sources/profondeur/map.c

SRCS_A		= sources/astar/main.c\
		  sources/astar/astar.c\
		  sources/astar/list.c\
		  sources/astar/map.c\
		  sources/astar/open_close.c

SRCS_GEN	= sources/generateur/main.c\
		  sources/generateur/error.c\
		  sources/generateur/print_maze.c\
		  sources/generateur/parfait.c\
		  sources/generateur/imparfait.c\
		  sources/generateur/init.c

OBJS_LAR	= $(SRCS_LAR:.c=.o)

OBJS_PRO	= $(SRCS_PRO:.c=.o)

OBJS_A		= $(SRCS_A:.c=.o)

OBJS_GEN	= $(SRCS_GEN:.c=.o)

CC		= gcc

RM		= rm -rf

CFLAGS		= -Wall -Wextra -Iinclude

all:		$(NAME_LAR) $(NAME_PRO) $(NAME_A) $(NAME_GEN) $(NAME_TOUR)

$(NAME_LAR): $(OBJS_LAR)
	mkdir -p largeur
	$(CC) -o $(NAME_LAR) $(OBJS_LAR) $(CFLAGS)

$(NAME_PRO): $(OBJS_PRO)
	mkdir -p profondeur
	$(CC) -o $(NAME_PRO) $(OBJS_PRO) $(CFLAGS)

$(NAME_A): $(OBJS_A)
	mkdir -p astar
	$(CC) -o $(NAME_A) $(OBJS_A) $(CFLAGS)

$(NAME_TOUR): $(OBJS_A)
	mkdir -p tournoi
	$(CC) -o $(NAME_TOUR) $(OBJS_A) $(CFLAGS)

$(NAME_GEN): $(OBJS_GEN)
	mkdir -p generateur
	$(CC) -o $(NAME_GEN) $(OBJS_GEN) $(CFLAGS)

clean:
	$(RM) $(OBJS_LAR) $(OBJS_PRO) $(OBJS_A) $(OBJS_GEN)

fclean:		clean
	$(RM) $(NAME_LAR) $(NAME_PRO) $(NAME_A) $(NAME_GEN) $(NAME_TOUR)
	$(RM) profondeur largeur generateur astar tournoi

re:		fclean all

.PHONY:		all clean fclean re
