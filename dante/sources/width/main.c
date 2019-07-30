/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "profondeur.h"

int pars_map(int x, int y, map_t *map, int i)
{
	map->map[y][x] = 'o';
	if (i == 174467)
		return (-1);
	else if (x == map->height - 1 && y == map->width - 1)
		return (0);
	if (x + 1 < map->height && map->map[y][x + 1] == '*') {
		if (pars_map(x + 1, y, map, i + 1) == 0)
			return (0);
	}
	else if (y + 1 < map->width && map->map[y + 1][x] == '*')
		if (pars_map(x, y + 1, map, i + 1) == 0)
			return (0);
	if (x - 1 >= 0 && map->map[y][x - 1] == '*') {
		if (pars_map(x - 1, y, map, i + 1) == 0)
			return (0);
	}
	else if (y - 1 >= 0 && map->map[y - 1][x] == '*')
		if (pars_map(x, y - 1, map, i + 1) == 0)
			return (0);
	map->map[y][x] = 'a';
	return (-1);
}

void change_map(map_t *map)
{
	for (int y  = 0; y != map->width; y++) {
		for (int x = 0; x != map->height; x++) {
			if (map->map[y][x] == 'a')
				map->map[y][x] = '*';
		}
	}
}

int main(int ac, char **av)
{
	map_t map;

	if (ac != 2)
		return (1);
	else if (get_map(&map, av[1]) == 1)
		return (1);
	if (map.width == 0)
		return (1);
	else if (pars_map(0, 0, &map, 0) == -1) {
		fprintf(stderr, "No path found!\n");
		return (1);
	}
	change_map(&map);
	print_map(&map);
	for (int i = 0; i != map.width; i++)
		free(map.map[i]);
	free(map.map);
	return (0);
}
