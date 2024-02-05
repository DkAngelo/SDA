#include "tree.h"
#include "elemtype.h"

Node* TreeCopy(const Node* t) {
    if (TreeIsEmpty(t)) {
        return NULL;
    }
    Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
    n->left = TreeCopy(TreeLeft(t));
    n->right = TreeCopy(TreeRight(t));
    return n;
}

Node* MergeTree(const Node* t1, const Node* t2) {
    
    Node* ret = TreeCreateEmpty();
    if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
        return ret;
    }
    else if (!TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
        ret = TreeCopy(t1);
        return ret;
    }
    else if (TreeIsEmpty(t1) && !TreeIsEmpty(t2)) {
        ret = TreeCopy(t2);
        return ret;
    }

    ElemType sum = *TreeGetRootValue(t1) + *TreeGetRootValue(t2);
    ret = TreeCreateRoot(&sum, NULL, NULL);
    ret->left = MergeTree(TreeLeft(t1), TreeLeft(t2));
    ret->right = MergeTree(TreeRight(t1), TreeRight(t2));

    return ret;
}