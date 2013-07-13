
#ifndef __ARM_NODE_H__
#define __ARM_NODE_H__

#include "arm_types.h"
#include "arm_men.h"
#include "arm_list.h"
#include <string.h>

typedef struct _ANode ANode;

struct _ANode
{
    apointer data;
    //
    ANode *next;
    ANode *prev;
    ANode *parent;
    ANode *children;
};


ANode* a_node_new               (apointer data);
ANode* a_node_init              (ANode *node);
ANode* a_node_free              (ANode *node);
ANode* a_node_prepend           (ANode *parent, ANode *node);
ANode* a_node_insert_before     (ANode *parent, ANode *sibling, ANode *node);
ANode* a_node_first_sibling     (ANode *node); /* 獲取第一個節點 */
ANode* a_node_last_sibling      (ANode *node); /* 獲取最後節點 */

/* 添加節點 */
#define a_node_append(parent, node)             \
    a_node_insert_before ((parent), NULL, (node))
/* 判斷是否爲root節點 */
#define A_NODE_IS_ROOT(node) ((ANode*)node->parent == NULL && \
        (ANode*)node->prev == NULL && \
        (ANode*)node->next == NULL)
/* 獲取第一個孩子節點 */
#define a_node_first_child(node) ((node) ? (ANode*)(node)->children : NULL)
/* 獲取下一個節點 */
#define a_node_next_sibling(node) ((node) ? (ANode*)(node)->next : NULL)
/* 獲取上一個節點 */
#define a_node_prev_sibling(node) ((node) ? (ANode*)(node)->prev : NULL)


#endif
