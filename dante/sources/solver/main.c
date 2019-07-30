/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** By DavidS
*/

#include <unistd.h>
#include <stdlib.h>
#include "astar.h"

void my_putsterror(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		write(2, &str[i], 1);
}

int main(int ac, char **av)
{
	map_t map;
	first_t	*f = NULL;

	if (ac != 2)
		return (1);
	else if (get_map(&map, av[1]) == 1)
		return (1);
	if ((f = init_first(&map)) == NULL)
		return (1);
	else if (astar(&map, f) == 1)
		return (1);
	print_map(&map);
	for (int i = 0; i != map.width; i++)
		free(map.map[i]);
	free(map.map);
	return (0);
}
