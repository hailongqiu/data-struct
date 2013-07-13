/* 多叉樹.
 */
#include "arm_node.h"


ANode* a_node_new (apointer data)
{
    ANode *node = a_new0(ANode);
    if (node)
        bzero(node, sizeof(ANode));
    node->data = data;
    node = a_node_init(node);
    return node;
}

ANode* a_node_init (ANode *node)
{
    node->prev = node->next = node->children = node->parent = NULL;
    return node;
}

ANode* a_node_prepend (ANode *parent, ANode *node)
{
    return a_node_insert_before(parent, parent->children, node);
}

ANode* a_node_insert_before (
        ANode *parent, 
        ANode *sibling, 
        ANode *node
        )
{
    // 添加的節點的父親節點指向parent.
    node->parent = parent;

    if (sibling)
    {
        /* node 始終插入sibling前.
         */
    }
    else
    {
        // 判斷父親節點下面是否有子孩子(葉節點)
        if (parent->children)
        {
            // 循環子節點(到最後一個結束).
            sibling = parent->children;

            while (sibling->next)
                sibling = sibling->next;
            // 尾節點連接新節點.
            node->prev = sibling;
            sibling->next = node;
        }
        else
        {
            node->parent->children = node;
        }
    }

    return NULL;
}

