#include "../inc/header.h"

static int find_not_neg_min(int *arr, int size);

void mx_init_maze(int x, int y, t_cell maze[x][y]) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            maze[j][i].cell = '.';
            maze[j][i].timemark = -1;
        }
    }
}

void mx_bfs_maze(int x, int y, t_cell maze[x][y], t_point start) {
    int x_st = start.x;
    int y_st = start.y;
    maze[x_st][y_st].timemark = 0;
    bool is_all_defined = 0;
    while(!is_all_defined) {
        is_all_defined = 1;
        for(int i = 0; i < y; i++) { //y coord
            for (int j = 0; j < x; j++) { //x coodr
                t_cell cur = maze[j][i];
                int near_vals[4] = {-1, -1, -1, -1};
                if (cur.cell == '#' || cur.timemark >= 0) continue;
                else {
                if (i != 0) 
                    near_vals[0] = maze[j][i - 1].timemark;
                if (i != y - 1) 
                    near_vals[1] = maze[j][i + 1].timemark;
                if (j != 0) 
                    near_vals[2] = maze[j - 1][i].timemark;
                if (j != x - 1) 
                    near_vals[3] = maze[j + 1][i].timemark;

                int mark = find_not_neg_min(near_vals, 4) + 1;
                maze[j][i].timemark = mark;
                if (mark > 0) is_all_defined = 0;
                }
            }
        }
    }
}

void mx_draw_path(int x, int y, t_cell maze[x][y], t_point end) {
    int cur_x = end.x;
    int cur_y = end.y;
    int cur_mark = maze[cur_x][cur_y].timemark;
    maze[cur_x][cur_y].cell = '*';
    if (cur_mark == 0) return;
    
    if (cur_x != 0) {
        if (maze[cur_x - 1][cur_y].timemark == cur_mark - 1) {
            t_point next;
            next.x = cur_x - 1;
            next.y = cur_y;
            mx_draw_path(x, y, maze, next);
            return;
        }
    }
    if (cur_x != x - 1) {
        if (maze[cur_x + 1][cur_y].timemark == cur_mark - 1) {
            t_point next;
            next.x = cur_x + 1;
            next.y = cur_y;
            mx_draw_path(x, y, maze, next);
            return;
        }
    }
    if (cur_y != 0) {
        if (maze[cur_x][cur_y - 1].timemark == cur_mark - 1) {
            t_point next;
            next.x = cur_x;
            next.y = cur_y - 1;
            mx_draw_path(x, y, maze, next);
            return;
        }
    }
    if (cur_y != y - 1) {
        if (maze[cur_x][cur_y + 1].timemark == cur_mark - 1) {
            t_point next;
            next.x = cur_x;
            next.y = cur_y + 1;
            mx_draw_path(x, y, maze, next);
            return;
        }
    }
}

static int find_not_neg_min(int *arr, int size) {
    int min = __INT_MAX__;
    bool is_found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min && arr[i] >= 0) {
            min = arr[i];
            is_found = true;
        }
    }
    if (is_found) return min;
    else return -2;
}

int mx_dist_define(int x, int y, t_cell maze[x][y]){
    int max = 0;
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            if (maze[j][i].timemark > max) max = maze[j][i].timemark;
        }
    }
    return max;
}
