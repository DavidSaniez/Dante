/*
** EPITECH PROJECT, 2018
** Perfect_map
** File description:
** By DavidS
*/

#include <stdlib.h>
#include "gen.h"

void change_north_west(char **map, int i, int j, dante_t *dante)
{
	if (i - 1 >= 0 && map[i - 1][j] == '1')
		dante->north = 1;
	if (j - 1 >= 0 && map[i][j - 1] == '1')
		dante->west = 1;
}

void one_wall_aside(char **map, int i, int j, dante_t *dante)
{
	if (i - 1 >= 0 && dante->north == 1 && dante->west == 0)
		map[i - 1][j] = '0';
	if (j - 1 >= 0 && dante->north == 0 && dante->west == 1)
		map[i][j - 1] = '0';
}

void two_walls_aside(char **map, int i, int j, int random)
{
	random = rand()%2;
	if (j - 1 >= 0 && random == 0)
		map[i][j - 1] = '0';
	if (i - 1 >= 0 && random == 1)
		map[i - 1][j] = '0';
}

void algo_parfait(dante_t *dante, char **map)
{
	int random = 0;
	for (int i = 0; i < dante->width; i +=2) {
		dante->north = 0;
		dante->west = 0;
		for (int j = 0; j < dante->height; j +=2) {
			if (i == 0)
				map[i][j] = '0';
			change_north_west(map, i, j, dante);
			one_wall_aside(map, i, j, dante);
			if (dante->north == 1 && dante->west == 1)
				two_walls_aside(map, i, j, random);
		}
	}
}

void gen_parfait(int height, int width)
{
	dante_t	dante;
	char **map;

	init_dante(&dante, height, width);
	if ((map = malloc_map(height, width)) == NULL)
		return;
	map = init_map(map, height, width);
	algo_parfait(&dante, map);
	modif_map(map, height, width);
}
