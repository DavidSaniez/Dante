/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** By DavidS
*/

#include <stdlib.h>
#include "astar.h"

int add_neighbor_in_open(first_t *f, open_t *neighbor)
{
	if (f != NULL) {
		neighbor->next = f->first;
		f->first = neighbor;
		return (0);
	}
	return (1);
}

int count_open(first_t *f)
{
	int nb_cells = 0;
	open_t	*tmp;

	if (f != NULL) {
		tmp = f->first;
		while (tmp != NULL) {
			if (tmp->closed == 0)
				nb_cells++;
			tmp = tmp->next;
		}
	}
	return (nb_cells);
}

first_t	*init_first(map_t *map)
{
	first_t	*f;
	open_t *open;

	if ((f = malloc(sizeof(first_t))) == NULL
	    || (open = malloc(sizeof(open_t))) == NULL)
		return (NULL);
	else if (f == NULL || open == NULL)
		return (NULL);
	open->x = 0;
	open->y = 0;
	open->h_cost = (map->height - 1) * 10 + (map->width - 1) * 10;
	open->closed = 0;
	open->next = NULL;
	open->parent = NULL;
	f->first = open;
	return (f);
}
