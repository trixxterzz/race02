#pragma once

#include "list.h"

typedef struct s_cell {
    char cell;
    int timemark;
}              t_cell;

typedef struct s_point {
    int x;
    int y;
}              t_point;

char *mx_getline(int file);
void mx_print_to_file(int x, int y, t_cell arr[x][y]);




void mx_get_maze_dim(int file, int *x, int *y);
void mx_parse_mazefile(int file, int x, int y, t_cell maze[x][y]);
void mx_init_maze(int x, int y, t_cell maze[x][y]);
void mx_bfs_maze(int x, int y, t_cell maze[x][y], t_point start);
void mx_draw_path(int x, int y, t_cell maze[x][y], t_point end);

bool mx_is_in_range(t_point start, t_point end, int x, int y);
bool mx_is_not_obstacle(char c);
bool mx_is_reachable(int mark);

int mx_dist_define(int x, int y, t_cell maze[x][y]);
void mx_print_to_out(int exit, int dist);
