
#ifndef __ARM_LIST_H__
#define __ARM_LIST_H__

#include "arm_types.h"
#include "arm_men.h"

typedef struct _AList AList;
typedef void (*AFunc) (apointer data, apointer user_data);

struct _AList{
    apointer data;
    AList *next;
    AList *prev;
};

AList* a_list_malloc    ();
AList* a_list_nth       (AList *list, auint n);
AList* a_list_append    (AList *list, apointer data);
AList* a_list_prepend    (AList *list, apointer data);
AList* a_list_insert    (AList *list, apointer data, aint position);
AList* a_list_remove    (AList *list, aconstpointer data);
AList* a_list_reverse   (AList *list);
auint  a_list_length    (AList *list);
AList* a_list_first     (AList *list);
AList* a_list_last      (AList *list);
AList* a_list_find      (AList *list, aconstpointer data);
aint   a_list_index     (AList *list, aconstpointer data);
void   a_list_free      (AList *list);
void   a_list_free_1    (AList *list);
void   a_list_foreach   (AList *list, AFunc func, apointer data);

// 主要用於遍歷鏈表的時候.
// 比如: while (list != NULL)
//          list = g_list_next(list); 
#define a_list_prev(list) ((list) ? (AList*)list->prev : NULL)
#define a_list_next(list) ((list) ? (AList*)list->next : NULL)
#define LIST_GET_DATA(list, type) (type)(((AList*)list)->data)


#endif
