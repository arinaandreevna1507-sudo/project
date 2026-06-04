#include <stdio.h>
#include "queue.h"

int main() {
    Queue* q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);

    int val;
    dequeue(q, &val);
    printf("Извлечено: %d\n", val);
    dequeue(q, &val);
    printf("Извлечено: %d\n", val);

    display(q);

    enqueue(q, 60);
    enqueue(q, 70);
    display(q);

    peek(q, &val);
    printf("Первый элемент: %d\n", val);

    destroyQueue(q);
    return 0;
}