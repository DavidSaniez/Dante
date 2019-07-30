/*
** EPITECH PROJECT, 2018
** print_map.c
** File description:
** By DavidS
*/

#include <stdio.h>

void print_map(char **map, int height, int width)
{
	int i = 0;
	int dont_print = 0;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (i == width - 1 && j == height - 1
			&& map[i][j] == '1') {
				printf("*");
				dont_print = 1;
			}
			if (map[i][j] == '0')
				printf("*");
			else if (map[i][j] == '1' && dont_print != 1)
				printf("X");
		}
		if (i != (width - 1))
			printf("\n");
	}
	map[i] = NULL;
}

void modif_map(char **map, int height, int width)
{
	int i = 0;
	int j = 0;

	while (i < width - 1)
		i++;
	while (j < height - 1)
		j++;
	if (map[i][j - 1] == '1' && map[i - 1][j] == '1')
		map[i][j - 1] = '0';
	print_map(map, height, width);
}
