/*
** EPITECH PROJECT, 2018
** initialize
** File description:
** By DavidS
*/

#include <stdlib.h>
#include "gen.h"

char **malloc_map(int height, int width)
{
	int i = 0;
	int max_larg = height + (height - 1);
	int max_haut = width + (width - 1);
	char **map;

	if (height == 0 || width == 0)
		return (NULL);
	else if ((map = malloc(sizeof(char *) * (max_haut + 1))) == NULL)
		return (NULL);
	while (i < max_haut) {
		if ((map[i] = malloc(sizeof(char) * (max_larg + 1))) == NULL)
			return (NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char **init_map(char **map, int height, int width)
{
	int j = 0;
	
	for (int i = 0; i < width + (width - 1); i++) {
		j = 0;
		while (j < height + (height - 1)) {
			if (j % 2 == 0 && i % 2 == 0)
				map[i][j] = '0';
			else if (j % 2 != 0 && i % 2 == 0)
				map[i][j] = '1';
			else if (i % 2 != 0)
				map[i][j] = '1';
			j++;
		}
		map[i][j] = '\0';
	}
	return (map);
}

void init_dante(dante_t *dante, int height, int width)
{
	dante->north = 0;
	dante->west = 0;
	dante->height = height + (height - 1);
	dante->width = width + (width - 1);
}
