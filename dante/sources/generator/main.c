/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** By DavidS
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gen.h"

int main(int argc, char **argv)
{
	srand(getpid() * time(NULL));
	if (argc == 3) {
		if (good_dimensions(argv[1], argv[2]) == -1)
			return (-1);
		gen_imparfait(atoi(argv[1]), atoi(argv[2]));
	} else if (argc == 4) {
		if (good_dimensions(argv[1], argv[2]) == -1
		    || my_strcmp("perfect", argv[3]) == 1)
			return (-1);
		gen_parfait(atoi(argv[1]), atoi(argv[2]));
	}
	return (0);
}
