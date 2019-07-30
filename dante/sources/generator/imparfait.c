/*
** EPITECH PROJECT, 2018
** imperfect
** File description:
** By DavidS
*/

#include <stdlib.h>
#include "gen.h"

void break_walls(char **map, int height, int width)
{
	int y = 0;
	int x = 0;
	int nb_walls_break = (height * width) / 2;

	for (int i = 0; i < nb_walls_break; i++) {
		y = rand()%width;
		x = rand()%height;
		if (map[y][x] == '1')
			map[y][x] = '0';
	}
}

void gen_imparfait(int height, int width)
{
	char **map;
	dante_t	dante;

	init_dante(&dante, height, width);
	if ((map = malloc_map(height, width)) == NULL)
		return;
	map = init_map(map, height, width);
	algo_parfait(&dante, map);
	break_walls(map, height, width);
	modif_map(map, height, width);
}
