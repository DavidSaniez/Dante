/*
** EPITECH PROJECT, 2018
** astar.c
** File description:
** By DavidS
*/

#include <stdlib.h>
#include "astar.h"

void neighbours_pos(open_t *neighbor, int y, int x)
{
	neighbor->y = y;
	neighbor->x = x;
}

open_t *lowest_h_cost(first_t *f)
{
	int save_i = 0;
	int min;
	open_t *tmp;

	if (f != NULL && f->first != NULL) {
		tmp = f->first;
		if ((min = get_min(f)) == -1)
			return (NULL);
		for (int i = 0; tmp != NULL; i++) {
			if (tmp->closed == 0 && min >= tmp->h_cost) {
				save_i = i;
				min = tmp->h_cost;
			}
			tmp = tmp->next;
		}
		return (return_actual(f, save_i));
	}
	return (NULL);
}

int set_neighbours(open_t *neighbor, map_t *map, first_t *f, open_t *actual)
{
	int ret = 0;

	if (neighbor->x >= 0 && neighbor->x < map->height
	    && neighbor->y >= 0 && neighbor->y < map->width
	    && map->map[neighbor->y][neighbor->x] != 'X'
	    && (ret = is_it_closed(f, neighbor->y, neighbor->x)) != 1) {
		if (ret == -1)
			return (1);
		else if ((ret = is_it_in_open(f, neighbor->y, neighbor->x)) != 1) {
			if (ret == -1)
				return (1);
			neighbor->closed = 0;
			neighbor->h_cost = ((map->height - 1)- neighbor->x) * 10
				+ ((map->width - 1) - neighbor->y) * 10;
			neighbor->parent = actual;
			if (add_neighbor_in_open(f, neighbor) == 1)
				return (1);
		}
	}
	return (0);
}

int get_neighbours(map_t *map, first_t *f, open_t *actual)
{
	open_t	*neighbor;

	for (int i = 0; i < 4; i++) {
		if ((neighbor = malloc(sizeof(open_t))) == NULL)
			return (1);
		else if (i == 0)
			neighbours_pos(neighbor, actual->y, actual->x - 1);
		if (i == 1)
			neighbours_pos(neighbor, actual->y, actual->x + 1);
		else if (i == 2)
			neighbours_pos(neighbor, actual->y - 1, actual->x);
		if (i == 3)
			neighbours_pos(neighbor, actual->y + 1, actual->x);
		else if (set_neighbours(neighbor, map, f, actual) == 1)
			return (1);
	}
	return (0);
}

int astar(map_t *map, first_t *f)
{
	open_t *actual;

	while (count_open(f) > 0) {
		if ((actual = lowest_h_cost(f)) == NULL)
			return (1);
		close_actual_from_open(f, actual);
		if (actual->y == map->width - 1 && actual->x == map->height - 1) {
			while (actual != NULL) {
				map->map[actual->y][actual->x] = 'o';
				actual = actual->parent;
			}
			return (0);
		}
		else if (get_neighbours(map, f, actual) == 1)
			return (1);
	}
	my_putsterror("No solution found\n");
	return (1);
}
