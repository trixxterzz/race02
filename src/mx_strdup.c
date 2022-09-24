#include "../inc/header.h"

char *mx_strdup(const char *str) {
    int len = mx_strlen(str);
    char *duplicate = mx_strnew(len);
    if (duplicate == NULL) return NULL;

    mx_strcpy(duplicate, str);
    return duplicate;
}

//int main() {}
