/*
** EPITECH PROJECT, 2018
** profondeur.h
** File description:
** By DavidS
*/

#ifndef PROFONDEUR_H_
# define PROFONDEUR_H_

typedef struct map_s
{
	int width;
	int height;
	char **map;
} map_t;

void print_map(map_t *);
int get_map(map_t *, char *);

#endif /* !PROFONDEUR_H_ */
