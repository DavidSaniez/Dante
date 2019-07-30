/*
** EPITECH PROJECT, 2018
** heigh.h
** File description:
** By DavidS
*/

#ifndef height_H_
# define height_H_

typedef struct pos_s
{
	int x;
	int y;
} pos_t;

typedef struct larg_s
{
	int block;
	pos_t pos;
	struct larg_s *son;
	struct larg_s *dad;
} larg_t;

typedef struct first_s
{
	larg_t *first;
} first_t;

typedef struct map_s
{
	int width;
	int height;
	char **map;
} map_t;

void print_map(map_t *);
int stock_map(map_t *, char *);
int get_map(map_t *, char *);
int add_to_the_list(first_t *, larg_t *, map_t *);
int add_sons(first_t *, larg_t *, map_t *);
larg_t *get_next(first_t *);
int height(first_t *, map_t *);
int not_already_in_list(first_t *, larg_t *);
void change_son_pos(larg_t *, int, int);
int count_open(first_t *);

#endif /* !height_H_ */
