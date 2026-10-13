//
// Created by vogelbaum on 15.08.24.
//

#ifndef UNTITLED1_LINKLIST_QUEUE_H
#define UNTITLED1_LINKLIST_QUEUE_H

#include "../sort/sor.h"
#define QUEUESIZE 1000

typedef struct {
    item_type q[QUEUESIZE+1];           /* body of queue */
    int first;                          /* position of first element */
    int last;                           /* position of last element */
    int count;                          /* number of queue elements */
} queue;

void init_queue(queue *q);
void enqueue(queue *q, item_type x);
item_type dequeue(queue *q);
item_type headq(queue *q);
item_type empty_queue(queue *q);
void print_queue(queue *q);

#endif //UNTITLED1_LINKLIST_QUEUE_H
