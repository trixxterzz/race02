#include "../inc/header.h"


char *mx_getline(int file) {
    char buff[2];
    buff[0] = ' ';
    buff[1] = '\0';
    char *line = NULL;
    char *tmp = line;
    while(read(file, buff, 1)) {
        if (buff[0] == '\n' || buff[0] == '\0') break;
        tmp = line;
        line = mx_strjoin(line, buff);
        free(tmp);
    }
    return line;
}

void mx_print_to_file(int x, int y, t_cell arr[x][y]){
    int file = open("path.txt", O_TRUNC|O_RDWR|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);
    if (file == -1){
        mx_printerr("error\n");
        exit(1);
    }
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            write(file, &arr[j][i].cell, 1);
        }
        write(file, "\n", 1);
    }
    int cl = close(file);
    if (cl == -1) {
        mx_printerr("error\n");
        exit(1);
    }
}
void mx_get_maze_dim(int file, int *x, int *y) {
    char *line = NULL;
    int linecount = 0;
    int x_size = 0;
    if ((line = mx_getline(file)) != NULL) {
        x_size = mx_strlen(line);
        linecount++;
        free(line);
    }
    while  ((line = mx_getline(file)) != NULL) {
        if (x_size != mx_strlen(line)) {
            //map not rectangular
            mx_printerr("map error\n");
            exit(1);
        }
        linecount++;
        free(line);
    }
    if (linecount == 0) {
        mx_printerr("map does not exist\n");
        exit(1);
    }
    *x = (x_size + 1) / 2;
    *y = linecount;
}

void mx_parse_mazefile(int file, int x, int y, t_cell maze[x][y]) {
    char *line = NULL;
    
    for (int i = 0; i < y; i++) { //in each line, i = y coord
        line = mx_getline(file);
        int line_cur = 0;
        for (int j = 0; j < x; j++) { //j = x coord
            if (line[line_cur] != '.' 
                && line[line_cur] != '#') {
                //forbidden char
                mx_printerr("map error\n");
                exit(1);
            }

            maze[j][i].cell = line[line_cur];
            line_cur += 2;
        }
        free(line);
    }
}

void mx_print_to_out(int exit, int dist){
    mx_printstr("dist=");
    mx_printint(dist);
    mx_printstr("\n");
    mx_printstr("exit=");
    mx_printint(exit);
    mx_printstr("\n");
}

