/* 二叉樹.
 */

#include "arm_tree.h"


static ATreeNode* a_tree_node_new (apointer key, apointer value)
{
    ATreeNode *node = a_new0(ATreeNode);
    
    node->left  = NULL;
    node->right = NULL;
    node->key   = key;
    node->value = value;

    return node;
}

static void a_tree_insert_internal(
        ATree *tree,
        apointer key,
        apointer value,
        aboolean replace
        )
{
    ATreeNode *node = NULL;
    if (!tree->root)
    {
        tree->root = a_tree_node_new(key, value);
        tree->nnodes++;
        return;
    }

    node = tree->root;
    int cmp = tree->key_compare(key, node->key, tree->key_compare_data);
}

void a_tree_insert (
        ATree *tree, 
        apointer key, 
        apointer value
        )
{
    a_tree_insert_internal(tree, key, value, FALSE);
}

ATree* a_tree_new(ACompareFunc key_func)
{
    return a_tree_new_full((ACompareDataFunc)key_func, NULL);
}

ATree* a_tree_new_full(
    ACompareDataFunc key_compare_func, 
    apointer key_compare_data)
{
    ATree *tree = a_new0(ATree);

    tree->root     = NULL;
    tree->nnodes   = 0;
    tree->key_compare = key_compare_func;
    //tree->

    return tree;
}




