#include <stdio.h>      // printf
#include <stdlib.h>     // malloc
#include <string.h>     // memcpy
#include "list.h"


/**
 * initial list capacity
 */
const int init_cap = 5;

/**
 * internal function that resizes list arrays to new capacity
 */
struct list *list_resize(struct list *list, int cap) {
    if(list != NULL) {
        int i=0;
        int (*iprior)[] = list->data.idata;
        struct list *(*lprior)[] = list->data.ldata;
        list->cap = cap;
        if(list->is_simple) {
            list->data.idata = malloc(sizeof(int) * cap);
            for( ; i < list->len && i < cap; i++) {
                (*list->data.idata)[i] = (*iprior)[i];
            }
            // memcpy(list->data, prior, list->len * sizeof(int));
            for( ; i < cap; i++) {
                (*list->data.idata)[i] = 0;
            }
        } else {
            list->data.ldata = malloc(sizeof(struct list *) * cap);
            for( ; i < list->len && i < cap; i++) {
                (*list->data.ldata)[i] = (*lprior)[i];
            }
            // memcpy(llist->data, prior, llist->len * sizeof(struct llist *));
            for( ; i < cap; i++) {
                (*list->data.ldata)[i] = NULL;
            }
        }
    }
    return list;
}

/**
 * Create simple, emtpy list.
 */
struct list *list_create() {
    struct list *p = malloc(sizeof(struct list));
    p->cap = p->len = 0;
    p->is_simple = 1;
    p->data.idata = NULL;
    p->data.ldata = NULL;
    return list_resize(p, init_cap);
}

/**
 * Create simple list initialized with values.
 */
struct list *list_from_values(int argn, int values[]) {
    struct list *res = list_create();
    if(argn > 0 && values != NULL) {
        for(int i=0; i < argn; i++) {
            list_add(res, (int)values[i]);
        }
    }
    return res;
}

/**
 * Create empty list that can store sub-lists.
 */
struct list *list_with_sublists() {
    struct list *p = malloc(sizeof(struct list));
    p->cap = p->len = 0;
    p->is_simple = 0;
    p->data.idata = NULL;
    p->data.ldata = NULL;
    return list_resize(p, init_cap);
}

/**
 * Create new list as copy of list.
 */
struct list *list_copy(struct list *list) {
    struct list *copy = list;
    if(list != NULL) {
        if(list->is_simple) {
            copy = list_create();       // make shallow copy
            for(int i=0; i < list->len; i++) {
                list_add(copy, (*list->data.idata)[i]);
            }
        } else {
            copy = list_with_sublists();    // make deep copy
            for(int i=0; i < list->len; i++) {
                struct list *l = (*list->data.ldata)[i];
                struct list *c = list_copy(l);
                list_add_list(copy, c);
            }
        }
    }
    return copy;
}

/**
 * Add simple element to list.
 */
struct list *list_add(struct list *list, int e) {
    if(list != NULL && list->is_simple) {
        if(list->len >= list->cap) {
            list_resize(list, list->cap * 2);
        }
        (*list->data.idata)[list->len] = e;
        list->len += 1;
    }
    return list;
}

/**
 * Add list to list with sub-lists.
 */
struct list *list_add_list(struct list *list, struct list *e) {
    if(list != NULL && ! list->is_simple) {
        if(list->len >= list->cap) {
            list_resize(list, list->cap * 2);
        }
        (*list->data.ldata)[list->len] = e;
        list->len += 1;
    }
    return list;
}

/**
 * internal function that prints list structures recursively.
 */
void list_print_(struct list *list, int level) {
    if(list != NULL) {
        if(level <= 1) {
            printf("[");
        }
        for(int i=0; i < list->len; i++) {
            printf(i==0? "" : ", ");    //, (*list->data)[i]);
            if(list->is_simple) {
                printf("%d", (*list->data.idata)[i]);
            } else {
                struct list *l = (*list->data.ldata)[i];
                list_print_(l, level+1);
                // for(int j=0; j < l->len; j++) {
                //     printf("%d", (*l->data.idata)[j]);
                // }
            }
        }
        if(level <= 1) {
            printf("]");
        }
    }
}

/**
 * Print list.
 */
void list_print(struct list *list) {
    list_print_(list, 0);
}
