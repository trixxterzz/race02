#include "../inc/header.h"


//static void print_timemarks(int x, int y, t_cell maze[x][y]);

int main(int argc, char *argv[]) {
    //check if args are valid
    if (argc != 6){
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(1);
    }
    char *filename = argv[1];
    int inputfile = open(filename, O_RDONLY);
    if (inputfile == -1) {
        mx_printerr("map does not exist\n");
        exit(1);
    }
    //get size of the maze
    int x, y;
    mx_get_maze_dim(inputfile, &x, &y);
    t_cell maze[x][y];
    //init the maze
    mx_init_maze(x, y, maze);
    //close the file
    close(inputfile);
    //parse maze
    inputfile = open(filename, O_RDONLY);
    mx_parse_mazefile(inputfile, x, y, maze);
    close(inputfile);
    //exexute BFS
    t_point start;
    start.x = mx_atoi(argv[2]);
    start.y = mx_atoi(argv[3]);
    t_point end;
    end.x = mx_atoi(argv[4]);
    end.y = mx_atoi(argv[5]);
    //check if those points are on the map
    if (!mx_is_in_range(start, end, x, y)){
        mx_printerr("point are out of map range\n");
        exit(1);
    }
    //check if those points are obstacles
    if (!mx_is_not_obstacle(maze[start.x][start.y].cell)){
        mx_printerr("entry point cannot be an obstacle\n");
        exit(1);
    }
    if (!mx_is_not_obstacle(maze[end.x][end.y].cell)){
        mx_printerr("exit point cannot be an obstacle\n");
        exit(1);
    }
    //check with athe task story
    mx_bfs_maze(x, y, maze, start);
    //check if the end point has a non -1 timemark
    if (!mx_is_reachable(maze[end.x][end.y].timemark)){
        mx_printerr("route not found\n");
        exit(1);
    }

    mx_draw_path(x, y, maze, end);
    //mark the farthest points in the maze with D
    //if it is in the path, mark it with X instead
    int dist = mx_dist_define(x, y, maze);
    int exit = maze[end.x][end.y].timemark;
    for (int i = 0; i < y; i++){
        for (int j = 0; j < y; j++){
            if (maze[j][i].timemark == dist){
                if (maze[j][i].cell == '*') maze[j][i].cell = 'X';
                if (maze[j][i].cell == '.') maze[j][i].cell = 'D';
            }
        }
    }
    mx_print_to_file(x, y, maze);
    mx_print_to_out(exit, dist);
}
/*
static void print_timemarks(int x, int y, t_cell maze[x][y]) {
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            mx_printint(maze[j][i].timemark);
            mx_printchar(' ');
        }
        mx_printchar('\n');
    }
}
*/
