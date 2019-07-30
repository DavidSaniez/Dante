/*
** EPITECH PROJECT, 2018
** astar.h
** File description:
** By DavidS
*/

#ifndef ASTAR_H_
# define ASTAR_H_

typedef struct open_s
{
	int x;
	int y;
	int h_cost;
	int closed;
	struct open_s *next;
	struct open_s *parent;
} open_t;

typedef struct first_s
{
	open_t *first;
} first_t;

typedef struct map_s
{
	int width;
	int height;
	char **map;
} map_t;

int get_min(first_t *);
open_t *return_actual(first_t *, int);
first_t*close_actual_from_open(first_t *, open_t *);
int is_it_closed(first_t *, int , int);
int is_it_in_open(first_t *, int , int);
void print_map(map_t *);
int stock_map(map_t *, char *);
int get_map(map_t *, char *);
int add_neighbor_in_open(first_t *, open_t *);
int count_open(first_t *);
first_t	*init_first(map_t *);
int astar(map_t *, first_t *);
void my_putsterror(char *);

#endif /* !ASTAR_H_ */
