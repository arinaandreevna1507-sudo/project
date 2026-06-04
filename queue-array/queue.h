#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;

Queue* createQueue(int capacity);
bool isEmpty(Queue* q);
bool isFull(Queue* q);
bool enqueue(Queue* q, int value);
bool dequeue(Queue* q, int *value);
bool peek(Queue* q, int *value);
void display(Queue* q);
void destroyQueue(Queue* q);

#endif