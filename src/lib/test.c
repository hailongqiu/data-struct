/* 測試
 * gcc test.c arm_list.c arm_men.c arm_queue.c arm_node.c
 */

#include <string.h>
#include "arm_data.h"


/* 冒泡排序测试 */
void temp_func(apointer data, apointer user_data)
{
    aint temp;

    if (LIST_GET_DATA(data, aint) > LIST_GET_DATA(user_data, aint))
    {
        temp = LIST_GET_DATA(user_data, aint);
        ((AList*)user_data)->data = (apointer)LIST_GET_DATA(data, aint);
        ((AList*)data)->data = (apointer)temp;
    }
}

/* 回調函數測試 */
void test_func(apointer data, apointer user_data)
{
    a_list_foreach((apointer)user_data, temp_func, (apointer)data);
}

void print_test_func(apointer data, apointer user_data)
{
    printf("data:%d\n", (aint)((AList*)data)->data);
}

int main(int argc, const char *argv[])
{
    // 鏈表測試.
    AList *list = NULL;
    // 添加元素(可以是任意類型的,但是必須的同等類型的).
    list = a_list_append(list, (apointer)550);
    list = a_list_append(list, (apointer)100);
    list = a_list_append(list, (apointer)12000);
    list = a_list_append(list, (apointer)10);
    list = a_list_append(list, (apointer)500);
    list = a_list_append(list, (apointer)1500);
    list = a_list_append(list, (apointer)220);

    a_list_foreach(list, test_func, (apointer)list);
    puts("排序号后:");
    a_list_foreach(list, print_test_func, (apointer)list);
    /*
    printf("列表元素的個數:%d\n", a_list_length(list));
    puts("===================================");
    // 隊列測試.
    AQueue *queue = NULL;
    queue = a_queue_new();

    a_queue_push_head(queue, "hai"); 
    a_queue_push_tail(queue, "long"); 
    a_queue_push_tail(queue, "qiu"); 
    a_queue_push_head(queue, "linux");
    printf("隊列元素個數:%d\n", queue->length);
    // 出隊列.
    // linux
    // hai
    // long
    // qiu
    puts((achar*)a_queue_pop_head(queue));
    puts((achar*)a_queue_pop_head(queue));
    puts((achar*)a_queue_pop_head(queue));
    puts((achar*)a_queue_pop_head(queue));
    //a_list_foreach(queue->head, test_func, "queue");
    puts("====================================");
    // 棧測試. 這裏的隊列是可以當棧用的.
    AQueue *stack = NULL;
    stack = a_queue_new();
    // 入棧.
    a_queue_push_head(stack, "1"); 
    a_queue_push_head(stack, "2"); 
    // 隊列的回調函數測試.
    a_queue_foreach(stack, test_func, "stack");
    a_queue_clear(stack);
    a_queue_push_head(stack, "3"); 
    printf("棧的元素個數:%d\n", a_queue_get_length(stack));
    // 出棧.
    // 3
    // 2
    // 1
    printf("stack出棧:%s\n", (achar*)a_queue_pop_head(stack));
    printf("stack出棧:%s\n", (achar*)a_queue_pop_head(stack));
    printf("stack出棧:%s\n", (achar*)a_queue_pop_head(stack));
    printf("棧的元素個數:%d\n", a_queue_get_length(stack));
    printf("stack是否爲空:%d\n", (aint)a_queue_is_empty(stack));
    puts("====================================");
    ANode *root = NULL;
    root = a_node_new("root");

    a_node_append(root, a_node_new("child1"));
    a_node_append(root, a_node_new("child2"));
    a_node_append(root, a_node_new("child3"));
    a_node_append(root->children, a_node_new("child1-1"));

    puts((achar*)root->data);
    puts((achar*)root->children->data);
    puts((achar*)root->children->children->data);
    puts("======================================");
    ATree *tree = a_tree_new(NULL);
    a_tree_insert(tree, "k", "liinux");
    */

    return 0;
}
