
#ifndef __ARM_QUEUE_H__
#define __ARM_QUEUE_H__

#include "arm_list.h"
#include "arm_men.h"

typedef struct _AQueue AQueue;

struct _AQueue
{
    AList *head; // 頭.
    AList *tail; // 尾.
    auint length; 
};

#define A_QUEUE_INIT {NULL, NULL, 0}

AQueue*      a_queue_new          (void);
void         a_queue_free         (void);
void         a_queue_init         (AQueue *queue);
void         a_queue_clear        (AQueue *queue);
aboolean     a_queue_is_empty     (AQueue *queue);
auint        a_queue_get_length   (AQueue *queue);
void         a_queue_foreach      (AQueue *queue, AFunc func, apointer user_data);
AList        a_queue_find         (AQueue *queue, aconstpointer user_data);
void         a_queue_push_head    (AQueue *queue, apointer data);
void         a_queue_push_tail    (AQueue *queue, apointer data);
void         a_queue_push_nth     (AQueue *queue, apointer data, aint n);
apointer     a_queue_pop_head     (AQueue *queue);
apointer     a_queue_pop_tail     (AQueue *queue);
void         a_queue_pop_nth      (AQueue *queue, apointer data, aint n);
aboolean     a_queue_remove       (AQueue *queue, aconstpointer data);
auint        a_queue_remove_all   (AQueue *queue, aconstpointer data);

#endif
