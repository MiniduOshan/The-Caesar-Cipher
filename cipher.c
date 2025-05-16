// cipher.c

#include <stdio.h>
#include <ctype.h>     
#include "cipher.h"    



// Check if the queue is empty
int IsQueueEmpty(const Queue *q) {
    return q->count == 0;
}

// Check if the queue is full
int IsQueueFull(const Queue *q) {
    return q->count == MAXQUEUE;
}


