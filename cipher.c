// cipher.c
#include <stdio.h>
#include <ctype.h>
#include "cipher.h"

// Initialize a circular queue
void CreateQueue(Queue *q) {
    q->count=0;
    q->front=0;
    q->rear=-1;
}

// dont need to use empty checker(not dequeuing)

// Check queue is full
int IsQueueFull(const Queue *q) {
    return q->count == MAXQUEUE;
}



