/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** By DavidS
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "astar.h"

void print_map(map_t *map)
{
	for (int i = 0; i != map->width; i++)
		printf("%s\n", map->map[i]);
}

int	detect_error(char *line, int height)
{
	if ((int)strlen(line) != height)
		return (1);
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] != '*' && line[i] != 'X')
			return (1);
	}
	return (0);
}

int stock_map(map_t *map, char *av)
{
	FILE *fd;
	size_t len = 0;
	char *str = NULL;

	if ((fd = fopen(av, "r")) == NULL)
		return (1);
	for (int i = 0; getline(&str, &len, fd) != -1; i++) {
		map->map[i] = strdup(str);
		map->map[i][map->height] = '\0';
		if (detect_error(map->map[i], map->height) == 1)
			return (1);
	}
	fclose(fd);
	return (0);
}

int get_map(map_t *map, char *av)
{
	FILE *fd;
	char *str = NULL;
	size_t len = 0;

	map->width = 0;
	if ((fd = fopen(av, "r")) == NULL)
		return (1);
	while (getline(&str, &len, fd) != -1)
		map->width = map->width + 1;
	map->height = strlen(str) - 1;
	fclose(fd);
	if ((map->map = malloc(sizeof(char *) * map->width)) == NULL)
		return (1);
	else if (stock_map(map, av) == 1)
		return (1);
	return (0);
}
