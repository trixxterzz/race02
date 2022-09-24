#include "../inc/list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    t_list *cur = *list;
    t_list *prev = NULL;
    t_list *nxt = cur->next;
    while (cur != NULL) {
        if (cmp(del_data, cur->data)) {
            if (prev == NULL) {
                *list = nxt;
                free(cur);
                cur = nxt;
                nxt = cur->next;
                continue;
            }

            prev->next = nxt;
            free(cur);
            cur = nxt;
            nxt = cur->next;
        }
        else {
            prev = cur;
            cur = nxt;
            nxt = cur->next;
        }
        
    }
}

//int main() {}
