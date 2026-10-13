//
// Created by vogelbaum on 15.09.2024.
//

#ifndef UNTITLED1_QUEUE_QUEUE_H
#define UNTITLED1_QUEUE_QUEUE_H

typedef struct QNode {
  int data;
  struct QNode *next;
  struct QNode *prev;
} QNode;

typedef struct MyQueue {
  struct QNode *front;
  struct QNode *rear;
  int size;
} MyQueue;


#endif //UNTITLED1_QUEUE_QUEUE_H
