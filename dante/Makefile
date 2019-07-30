##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## By DavidS
##

NAME_LAR	= height/solver

NAME_PRO	= width/solver

NAME_A		= solver/solver

NAME_TOUR	= tournament/solver

NAME_GEN	= generator/generator

SRCS_LAR	= sources/height/main.c\
		  sources/height/map.c\
		  sources/height/largeur.c

SRCS_PRO	= sources/width/main.c\
		  sources/width/map.c

SRCS_A		= sources/solver/main.c\
		  sources/solver/astar.c\
		  sources/solver/list.c\
		  sources/solver/map.c\
		  sources/solver/open_close.c

SRCS_GEN	= sources/generator/main.c\
		  sources/generator/error.c\
		  sources/generator/print_maze.c\
		  sources/generator/parfait.c\
		  sources/generator/imparfait.c\
		  sources/generator/init.c

OBJS_LAR	= $(SRCS_LAR:.c=.o)

OBJS_PRO	= $(SRCS_PRO:.c=.o)

OBJS_A		= $(SRCS_A:.c=.o)

OBJS_GEN	= $(SRCS_GEN:.c=.o)

CC		= gcc

RM		= rm -rf

CFLAGS		= -Wall -Wextra -Iinclude

all:		$(NAME_LAR) $(NAME_PRO) $(NAME_A) $(NAME_GEN) $(NAME_TOUR)

$(NAME_LAR): $(OBJS_LAR)
	mkdir -p height
	$(CC) -o $(NAME_LAR) $(OBJS_LAR) $(CFLAGS)

$(NAME_PRO): $(OBJS_PRO)
	mkdir -p width
	$(CC) -o $(NAME_PRO) $(OBJS_PRO) $(CFLAGS)

$(NAME_A): $(OBJS_A)
	mkdir -p solver
	$(CC) -o $(NAME_A) $(OBJS_A) $(CFLAGS)

$(NAME_TOUR): $(OBJS_A)
	mkdir -p tournament
	$(CC) -o $(NAME_TOUR) $(OBJS_A) $(CFLAGS)

$(NAME_GEN): $(OBJS_GEN)
	mkdir -p generator
	$(CC) -o $(NAME_GEN) $(OBJS_GEN) $(CFLAGS)

clean:
	$(RM) $(OBJS_LAR) $(OBJS_PRO) $(OBJS_A) $(OBJS_GEN)

fclean:		clean
	$(RM) $(NAME_LAR) $(NAME_PRO) $(NAME_A) $(NAME_GEN) $(NAME_TOUR)
	$(RM) profondeur largeur generateur astar tournoi

re:		fclean all

.PHONY:		all clean fclean re
