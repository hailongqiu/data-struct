
/*
 * 使用的雙向鏈表.
 * *prev(上一個) *next(下一個).
 * (測試) gcc arm_list.c arm_men.c [注意]需要去掉main函數的所有註釋.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "arm_list.h"

/* malloc的封裝.
 */
AList* a_list_malloc()
{
    AList *temp = a_new0(AList);
    if (temp)
        bzero(temp, sizeof(AList));
    return temp;
}

/* free的封裝.
 */
void a_free(AList *list)
{
    free(list);
    list = NULL;
}

/* 創建一個AList *節點.
 */
static inline AList* new_node(AList *prev, apointer data, AList *next)
{
    /* 創建node */
    AList *node = a_list_malloc();
    /* 初始化node */
    node->data = data;
    node->prev = prev;
    node->next = next;
    /* 尾節點 指向 新的節點 */
    if (prev)
        prev->next = node;
    /*  */
    if (next)
        next->prev = node;
    return node;
}

/* 在尾插入一個AList *節點.
 */
AList* a_list_append(AList *list, apointer data)
{
    AList *temp = new_node(a_list_last(list), data, NULL);
    return list ? list : temp;
}

/* 刪除 指定data 相似的節點.
 * @ list :
 * @ data :
 */
AList* a_list_remove(AList *list, aconstpointer data)
{
    AList *tmp = list;
    
    while (tmp)
    {
        if (tmp->data != data)
        {
            tmp  = tmp->next;
        }
        else
        {
            // 判斷prev是否爲NULL.
            if (tmp->prev)
                tmp->prev->next = tmp->next;
            // 判斷next是否爲NULL.
            if (tmp->next)
                tmp->next->prev = tmp->prev;
            // 如果爲第一個節點.
            if (list == tmp)
                list = list->next;

            a_list_free_1(tmp);
            break;
        }
    }
    
    return list;
}

/* 獲取所有節點總個數.
 * @ list :
 */
auint  a_list_length(AList *list)
{
    int length = 0;

    while (list)
    {
        length++;
        list = list->next;
    }

    return length;
}

/* 獲取第一個節點 
 * */
AList* a_list_first(AList *list)
{
    if (list)
    {
        while (list->prev)
            list = list->prev;
    }

    return list;
}

/* 獲取最後一個節點 
 * */
AList* a_list_last(AList *list)
{
    if (list)
    {
        while (list->next)
            list = list->next;
    }

    return list;
}

/* 釋放一個節點 
 * */
void a_list_free_1(AList *list)
{
    a_free(list);
}

/* 釋放全部節點 
 * */
void a_list_free(AList *list)
{
    while (list)
    {
        AList *next = list->next;
        a_list_free_1(list);
        list = next;
    }
}

/* 往list前面插入一個節點.
 * @ list: AList 類型節點.
 * @ data: void* 數據.
 * 返回一個AList類型.
 */
AList* a_list_prepend(AList *list, apointer data)
{
    AList *new_list;

    new_list = a_list_malloc();
    new_list->data = data;
    new_list->next = list;

    if (list) 
    {
        // 
        new_list->prev = list->prev;
        // 判斷是否不爲第一個節點.
        if (list->prev)
            // list的上一個節點指向新的節點.
            list->prev->next = new_list;
        list->prev = new_list;
    }
    else
        new_list->prev = NULL;

    return new_list;
}

/* 在指定位置(position)插入一個節點.
 * @ list :
 * @ data :
 * @ position :
 */
AList* a_list_insert(AList *list, apointer data, aint position)
{
    AList *new_list;
    AList *tmp_list;

    if (position < 0)
        return a_list_append(list, data);
    else if (position == 0)
        return a_list_prepend(list, data);

    tmp_list = a_list_nth(list, position);
    // tmp_list 爲NULL.(當position超過節點個數, tmp_list爲NULL) 
    if (!tmp_list)
        return a_list_append(list, data);

    new_list = a_list_malloc();
    new_list->data = data;
    // 在tmp_list前插入新節點.
    new_list->prev = tmp_list->prev; 
    tmp_list->prev->next = new_list;
    new_list->next = tmp_list;
    tmp_list->prev = new_list;

    return list;
}

/* 將移動到n指定的位置.
 * 返回一個AList*.
 */
AList* a_list_nth(AList *list, auint n)
{
    while ((n-- > 0) && list)
        list = list->next;

    return list;
}

/* 查找data的所在位置,幷返回它所在位置的AList*類型. 
 */
AList* a_list_find(AList *list, aconstpointer data)
{
    while (list)
    {
        if (list->data == data)
            return list;

        list = list->next;
    }

    return NULL;
}

/* 查找data的所在位置,並返回它所在的位置的aint.
 */
aint a_list_index(AList *list, aconstpointer data)
{
    aint index = 0;

    while (list)
    {
        if (list->data == data)
            return index;
        index++;
        list = list->next;
    }

    return -1;
}

//typedef void (*AFunc) (apointer data, apointer user_data);
/* 
 */
void a_list_foreach(AList *list, AFunc func, apointer user_data)
{
    /* 回調函數 */
    while (list)
    {
        //(*func)(list->data, user_data);
        func((apointer)list, user_data);
        list = list->next;
    }
}

/* 倒序節點.
 */
AList* a_list_reverse(AList *list)
{
    AList *last = NULL;

    while (list)
    {
        last = list; 
        list = last->next;
        last->next = last->prev;
        last->prev = list;
    }

    return last;
}

/* 回調函數測試 */
//void test_func(apointer data, apointer user_data)
//{
//    printf("data:%s user_data:%s \n", (char*)data, (char*)user_data);
//    if (strcmp((char*)data, (char*)user_data) > 0)
//        printf("這個數大於:%s\n", (char*)user_data);
//}

/* 測試 */
//int main(int argc, const char *argv[])
//{
//    AList *list_test = NULL;
//    /* 添加 */
//    list_test = a_list_append(list_test, "atring");
//    list_test = a_list_append(list_test, "seconed");
//    list_test = a_list_append(list_test, "hailongqiu");
//    /* 刪除 */
//    //list_test = a_list_remove(list_test, "hailongqiu");
//    /* 插入 */
//    list_test = a_list_insert(list_test, "homgingman", 4);
//
//    /* 查找 */
//    //if (a_list_find(list_test, "seconed"))
//    //    puts("--------------");
//
//    /* 測試 */
//    //puts((char*)list_test->data);
//    //puts((char*)list_test->next->data);
//    //puts((char*)list_test->next->next->data);
//    //puts((char*)list_test->prev->next->data);
//    //puts((char*)list_test->next->data);
//    //puts((char*)list_test->prev->data);
//    //puts((char*)list_test->next->next->data);
//
//    printf("一共有多少個元素:%d\n", a_list_length(list_test));
//    // 類似於 c# 的foreach.
//    puts("====================================");
//    a_list_foreach(list_test, test_func, "linux");
//    // index.
//    printf("a_list_index:%d\n", a_list_index(list_test, "atring"));
//    return 0;
//}

