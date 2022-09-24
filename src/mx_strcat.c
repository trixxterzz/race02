#include "../inc/header.h"

char *mx_strcat(char *s1, const char *s2) {
    int len = mx_strlen(s1);
    int i = 0;
    while (s2[i] != '\0') {
       s1[len + i] = s2[i];
       i++;
    }
    //add \0 byte
    s1[len + i] = '\0';
    return s1;
}

