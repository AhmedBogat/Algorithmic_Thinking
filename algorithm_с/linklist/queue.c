#include <stddef.h>
#include <malloc.h>


typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value) {
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;
  if (rear == NULL) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int dequeue() {
  if (front == NULL) {
    printf("Queue Underflow. Queue is empty.\n");
    return -1;
  }
  Node *temp = front;
  int dequeuedData = temp->data;
  front = front->next;
  if (front == NULL) {
    rear = NULL;
  }
  free(temp);
  return dequeuedData;
}

int peek() {
  if (front == NULL) {
    return -1;
  }
  return front->data;
}
void display() {
  Node *temp = front;
  if (temp == NULL) {
    printf("Queue is empty.\n");
    return;
  }
  while (temp) {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
  printf("\n");
}


void Qr() {
  enqueue(19);
  enqueue(20);
  enqueue(30);
  printf("First element:%d\n",peek());
  display();
}
/*

void init_queue(queue *q) {
  q->first = 0;
  q->last = QUEUESIZE - 1;
  q->count = 0;
}

void enqueue(queue *q, item_type x) {
  if (q->count >= QUEUESIZE) {
    printf("Warning: queue overflow enqueue x=%d\n", x);
  } else {
    q->last = (q->last + 1) % QUEUESIZE;
    q->q[q->last] = x;
    q->count = q->count + 1;
  }
}

item_type dequeue(queue *q) {
  item_type x;
  if (q->count <= 0)
    printf("Warning: empty queue dequeue.\n");

  x = q->q[q->first];
  q->first = (q->first + 1) % QUEUESIZE;
  q->count = q->count - 1;
  return (x);
}

item_type headq(queue *q) {
  return (q->q[q->first]);
}

item_type empty_queue(queue *q) {
  if (q->count <= 0) {
    return (true);
  }
  return (false);
}

void print_queue(queue *q) {
  int i = q->first;
  while (i != q->last) {
    printf( "%d", q->q[i]);
    i = (i + 1) % QUEUESIZE;
  }
  printf("%2d",q->q[i]);
  printf("\n");
}*/
