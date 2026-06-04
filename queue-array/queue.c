#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    q->size = 0;
    return q;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

bool isFull(Queue* q) {
    return q->size == q->capacity;
}

bool enqueue(Queue* q, int value) {
    if (isFull(q)) {
        return false;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
    return true;
}

bool dequeue(Queue* q, int *value) {
    if (isEmpty(q)) {
        return false;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return true;
}

bool peek(Queue* q, int *value) {
    if (isEmpty(q)) {
        return false;
    }
    *value = q->data[q->front];
    return true;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Очередь пуста.\n");
        return;
    }
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

void destroyQueue(Queue* q) {
    free(q->data);
    free(q);
}