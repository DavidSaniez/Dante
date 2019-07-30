/*
** EPITECH PROJECT, 2018
** height.h
** File description:
** By DavidS
*/

#include <stdlib.h>
#include "height.h"

int add_to_the_list(first_t *f, larg_t *son, map_t *map)
{
	larg_t *tmp;

	if (f == NULL || f->first == NULL || son == NULL)
		return (-1);
	if (son->pos.x >= 0 && son->pos.x < map->height
	    && son->pos.y >= 0 && son->pos.y < map->width
	    && map->map[son->pos.y][son->pos.x] != 'X'
	    && not_already_in_list(f, son) == 0) {
		tmp = f->first;
		while (tmp->son != NULL)
			tmp = tmp->son;
		tmp->son = son;
		son->block = 0;
		son->son = NULL;
	}
	return (0);
}

int add_sons(first_t *f, larg_t *actual, map_t *map)
{
	larg_t *son;

	for (int i = 0; i < 4; i++) {
		if ((son = malloc(sizeof(larg_t))) == NULL)
			return (-1);
		if (i == 0)
			change_son_pos(son, actual->pos.y - 1, actual->pos.x);
		else if (i == 1)
			change_son_pos(son, actual->pos.y + 1, actual->pos.x);
		if (i == 2)
			change_son_pos(son, actual->pos.y, actual->pos.x - 1);
		else if (i == 3)
			change_son_pos(son, actual->pos.y, actual->pos.x + 1);
		if (add_to_the_list(f, son, map) == -1)
			return (-1);
		son->dad = actual;
	}
	return (0);
}

larg_t *get_next(first_t *f)
{
	larg_t *tmp = f->first;;

	if (f == NULL || f->first == NULL)
		return (NULL);
	while (tmp != NULL && tmp->block == 1)
		tmp = tmp->son;
	return (tmp);
}

int height(first_t *f, map_t *map)
{
	larg_t *actual;

	if (f == NULL)
		return (-1);
	while (count_open(f) > 0) {
		if ((actual = get_next(f)) == NULL)
			return (-1);
		actual->block = 1;
		if (actual->pos.y == map->width - 1
		    && actual->pos.x == map->height - 1) {
			while (actual->dad != NULL) {
				map->map[actual->pos.y][actual->pos.x] = 'o';
				actual = actual->dad;
			}
			map->map[actual->pos.y][actual->pos.x] = 'o';
			return (0);
		}
		if (add_sons(f, actual, map) == -1)
			return (-1);
		actual = actual->son;
	}
	return (1);
}
