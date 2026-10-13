//
// Created by vogelbaum on 21.07.24.
//

#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H

#include "../sort/item.h"

typedef struct list {
    item_type item;
    struct list *next;
} list;
#endif //UNTITLED1_LIST_H
