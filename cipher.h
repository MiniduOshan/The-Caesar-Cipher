// cipher.h
// Caesar Cipher header file with circular queue

#ifndef CIPHER_H
#define CIPHER_H

#define MAXQUEUE 26       // Maximum queue size for A-Z
#define TRUE 1
#define FALSE 0

typedef char QueueElement;

// Circular queue structure
typedef struct {
    int count;                   // Current number of items
    int front;                   // Index of first item
    int rear;                    // Index of last item
    QueueElement items[MAXQUEUE];// Array for characters
} Queue;

// Set up an empty queue
void CreateQueue(Queue *q);

// Check if queue has no items
int IsQueueEmpty(const Queue *q);

// Check if queue is full
int IsQueueFull(const Queue *q);

// Add item to the end of the queue
void Append(Queue *q, QueueElement x);

// Remove item from the front of the queue
void Serve(Queue *q, QueueElement *x);

// Fill the queue with letters A-Z
void InitAlphabetQueue(Queue *q);

// Encrypt one character by shifting
char EncryptChar(char ch, int shift);

// Decrypt one character by shifting back
char DecryptChar(char ch, int shift);

// Encrypt a whole message
void EncryptMessage(char *message, int shift, char *result);

// Decrypt a whole message
void DecryptMessage(char *message, int shift, char *result);

#endif
