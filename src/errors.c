#include "../inc/header.h"

bool mx_is_in_range(t_point start, t_point end, int x, int y){
    bool res = true;
    if (start.x >= x
        || start.y >= y
        || end.x >= x
        || end.y >= y){
            res = false;
    }
    if (start.x < 0
        || start.y < 0
        || end.x < 0
        || end.y < 0){
            res = false;
    }
    return res;
}

bool mx_is_not_obstacle(char c){
    bool res = true;
    if (c == '#') res = false;
    return res;
}

bool mx_is_reachable(int mark){
    bool res = true;
    if (mark == -1) res = false;
    return res;
}

