/*
** EPITECH PROJECT, 2018
** open_close
** File description:
** By DavidS
*/

#include <stdlib.h>
#include "astar.h"

int get_min(first_t *f)
{
	open_t *tmp;

	tmp = f->first;
	while (tmp != NULL && tmp->closed != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return (-1);
	else if (tmp->closed == 0)
		return (tmp->h_cost);
	return (-1);
}

open_t *return_actual(first_t *f, int save_i)
{
	int i = 0;
	open_t *tmp = f->first;

	while (tmp != NULL && i != save_i) {
		i++;
		tmp = tmp->next;
	}
	return (tmp);
}

first_t	*close_actual_from_open(first_t *f, open_t *actual)
{
	open_t*tmp = f->first;

	if (f == NULL || actual == NULL)
		return (NULL);
	while (tmp != NULL) {
		if (tmp->x == actual->x && tmp->y == actual->y) {
			tmp->closed = 1;
			return (f);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int is_it_closed(first_t *f, int y, int x)
{
	open_t *tmp;

	if (f != NULL) {
		tmp = f->first;
		while (tmp != NULL) {
			if (y == tmp->y && x == tmp->x && tmp->closed == 1)
				return (1);
			tmp = tmp->next;
		}
		return (0);
	}
	return (-1);
}

int is_it_in_open(first_t *f, int y, int x)
{
	open_t	*tmp;

	if (f != NULL) {
		tmp = f->first;
		while (tmp != NULL) {
			if (y == tmp->y && x == tmp->x && tmp->closed == 0)
				return (1);
			tmp = tmp->next;
		}
		return (0);
	}
	return (-1);
}
