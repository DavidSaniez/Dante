/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** By DavidS
*/
#include <stdio.h>
#include <stdlib.h>
#include "height.h"

first_t *init_first()
{
	first_t	*f;
	larg_t *init;

	if ((init = malloc(sizeof(larg_t))) == NULL
	    || (f = malloc(sizeof(first_t))) == NULL)
		return (NULL);
	init->block = 0;
	init->pos.x = 0;
	init->pos.y = 0;
	init->son = NULL;
	init->dad = NULL;
	f->first = init;
	return (f);
}

int count_open(first_t *f)
{
	int nb_open = 0;
	larg_t *tmp = f->first;

	if (f == NULL || f->first == NULL)
		return (0);
	while (tmp != NULL) {
		if (tmp->block == 0)
			nb_open++;
		tmp = tmp->son;
	}
	return (nb_open);
}

void change_son_pos(larg_t *son, int y, int x)
{
	son->pos.y = y;
	son->pos.x = x;
}

int not_already_in_list(first_t *f, larg_t *son)
{
	larg_t *tmp = f->first;

	if (f == NULL || f->first == NULL || son == NULL)
		return (1);
	while (tmp != NULL) {
		if (tmp->pos.x == son->pos.x
		    && tmp->pos.y == son->pos.y)
			return (1);
		tmp = tmp->son;
	}
	return (0);
}

int main(int ac, char **av)
{
	int ret_larg = 0;;
	map_t map;
	first_t	*f = NULL;

	if (ac != 2)
		return (1);
	else if (get_map(&map, av[1]) == 1)
		return (1);
	if ((f = init_first()) == NULL)
		return (1);
	else if ((ret_larg = height(f, &map)) == -1)
		return (1);
	if (ret_larg == 1) {
		fprintf(stderr, "No solution found\n");
		return (1);
	}
	print_map(&map);
	return (0);
}
