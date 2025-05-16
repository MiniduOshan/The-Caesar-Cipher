#ifndef CIPHER_H
#define CIPHER_H

#define MAXQUEUE 26       // Maximum queue size for A-Z
#define TRUE 1
#define FALSE 0

typedef char QueueElement;


typedef struct {
    int count;                   // Current number of items
    int front;                   // Index of first item
    int rear;                    // Index of last item
    QueueElement items[MAXQUEUE];// Array for characters
} Queue;

