/*
** EPITECH PROJECT, 2018
** height.h
** File description:
** By DavidS
*/
/
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
  t_pos pos;
  struct larg_s	*son;
  struct larg_s	*dad;
} t_larg;

typedef struct first_s
{
	t_larg *first;
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
int add_to_the_list(first_t *, t_larg *, map_t *);
int add_sons(first_t *, t_larg *, map_t *);
t_larg *get_next(first_t *);
int height(first_t *, map_t *);
int not_already_in_list(first_t *, t_larg *);
void change_son_pos(t_larg *, int , int );
int count_open(first_t *);

#endif /* !height_H_ */
