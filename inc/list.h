#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);
bool mx_isdigit(int c);
bool mx_isspace(int c);
int mx_atoi(const char *str);

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_back(t_list **list);
void mx_pop_front(t_list ** list);
int mx_list_size(t_list *list);
void mx_push_index(t_list **list, void *data, int index);
void mx_pop_index(t_list **list, int index);
void mx_clear_list(t_list **list);
void mx_foreach_list(t_list *list, void (*f)(t_list *node));
t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b));
void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b));

char *mx_strcat(char *s1, const char *s2);
char *mx_strchr(const char *s, int c);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strjoin(char const *s1, char const *s2);
int mx_strcmp(const char *s1, const char *s2);
