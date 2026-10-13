//
// Created by vogelbaum on 01.08.24.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include "../sort/item.h"

typedef struct tree {
    item_type item;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;
#endif
