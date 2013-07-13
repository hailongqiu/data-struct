
#ifndef __ARM_TREE_H__
#define __ARM_TREE_H__

#include "arm_types.h"
#include "arm_men.h"

typedef struct _ATree ATree;
typedef struct _ATreeNode ATreeNode;
typedef aboolean (*ATraverseFunc) (apointer key, 
                                   apointer value, 
                                   apointer data);

struct _ATree
{
    ACompareDataFunc  key_compare;
    ATreeNode         *root;
    auint             nnodes;
    apointer          key_compare_data;
};

struct _ATreeNode
{
    apointer    key;
    apointer    value;
    //
    ATreeNode   *left;
    ATreeNode   *right;
    // (1) 左右子树深度之差的绝对值不超过1;
    // (2) 左右子树仍然为平衡二叉树.
    // 平衡因子BF = 左子樹深度 - 右子树深度.
    // 平衡因子只能 1, 0, -1, 
    // 其絕對值超過1, 則該二叉樹就是不平衡的
    gint8     balance; // 平衡
    guint8    left_child; // 判斷該節點是否有左孩子
    guint8    right_child; // 判斷....是否有右孩子
};

static ATreeNode* a_tree_node_new     (apointer key, apointer value);
ATree* a_tree_new                     (ACompareFunc func);
ATree* a_tree_new_full                (ACompareDataFunc key__compare_func, 
                                       apointer key_compare_data);
static void a_tree_insert_internal    (ATree *tree,
                                       apointer key,
                                       apointer value,
                                       aboolean replace);

void a_tree_insert                    (ATree *tree, 
                                       apointer key, 
                                       apointer value);
#endif

