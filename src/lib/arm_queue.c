/*
 * 隊列(Queue).
 * (測試) gcc arm_queue.c arm_list.c arm_men.c 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arm_queue.h"

AQueue* a_queue_new (void)
{
    AQueue *new = a_new0(AQueue); 
    if (new)
    {
        //memset(new, 0, sizeof(AQueue));
        bzero(new, sizeof(AQueue));
        a_queue_init(new);
    }
        
    return new;
}

void a_queue_init (AQueue *queue)
{
    queue->head = queue->tail = NULL;
    queue->length = 0;
}

void a_queue_push_tail(AQueue *queue, apointer data)
{
    queue->tail = a_list_append(queue->tail, data);
    if (queue->tail->next)
    {
        queue->tail = queue->tail->next;
    }
    else
    {
        queue->head = queue->tail;
    }
    queue->length++;
}

void a_queue_push_head(AQueue *queue, apointer data)
{
    queue->head = a_list_prepend(queue->head, data);

    if (!queue->tail)
        queue->tail = queue->head;
    queue->length++;
}

apointer a_queue_pop_head (AQueue *queue)
{
    if (queue->head) 
    {
        AList *node = queue->head;
        apointer data = node->data;

        queue->head = node->next;
        // 判斷下一個節點是否爲NULL.
        if (queue->head)
            queue->head->prev = NULL;
        else // 如果是NULL,證明沒有節點了.
            queue->tail = NULL;

        // 釋放node,並返回data.
        a_list_free_1(node);
        queue->length--;
        return data;
    }
    
    return NULL;
}

apointer a_queue_pop_tail(AQueue *queue)
{
    if (queue->tail)
    {
        AList *node = queue->tail;
        apointer data = node->data;
        
        queue->tail = node->prev;

        if (queue->tail)
            queue->tail->next = NULL;
        else
            queue->head = NULL;
        
        queue->length--;
        a_list_free_1(node);
        return data;
    }

    return NULL;
}


aboolean a_queue_is_empty (AQueue *queue)
{
    return queue->head == NULL;
}

auint a_queue_get_length (AQueue *queue)
{
    return queue->length;
}

void a_queue_clear(AQueue *queue)
{
    a_list_free(queue->head);
    a_queue_init(queue);
}

void a_queue_foreach(AQueue *queue, AFunc func, apointer user_data)
{
    AList *list;

    list = queue->head;
    while (list)
    {
        AList *next = list->next;
        func(list->data, user_data);
        list = next;
    }
}

//int main(int argc, const char *argv[])
//{
//    AQueue *queue = NULL; 
//    queue = a_queue_new();
//    a_queue_init(queue);
//
//    // 這段代碼有什麼意思嗎?
//    #define A_STMT_START do
//    #define A_STMT_END   while(0)
//    #define a_return_if_fail(expr) A_STMT_START{ (void)0; }A_STMT_END
//    a_return_if_fail(queue != NULL);
//    // 上面的函數展開.
//    /*
//    queue != NULL;
//    do
//    {
//        (void)0;
//    } while(0);
//    */
//
//    a_queue_push_tail(queue, "hai"); 
//    a_queue_push_tail(queue, "long"); 
//    a_queue_push_tail(queue, "qiu"); 
//    a_queue_push_head(queue, "linux");
//
//    puts((char*)queue->head->data);
//    puts((char*)queue->head->next->data);
//    puts((char*)queue->head->next->next->data);
//    puts((char*)queue->head->next->next->next->data);
//
//    return 0;
//}
