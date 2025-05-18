#ifndef CIPHER_H
#define CIPHER_H  // Header guard

#define MAXQUEUE 26  // Queue size

#define TRUE 1       // Boolean value
#define FALSE 0     

typedef char QElement;  // Queue item

typedef struct {
    int count;              // Item count
    int front;              // Front index 
    int rear;               // Rear index
    QElement items[MAXQUEUE]; // Data array
} Queue;

// Queue functions
void CreateQueue(Queue *q);        // Init queue
int IsFull(const Queue *q);        // Full check
void Append(Queue *q, QElement x); // Add item

// Cipher functions
void Encrypt(char *message, int shift, char *output); // Encrypt text
void Decrypt(char *message, int shift, char *output); // Decrypt text

// Helpers
void ToAlphaQueue(Queue *q);        // Fill A-Z
int FindQIndex(Queue *q, char target); // Find index
char ShiftChar(Queue *q, char ch, int shift, int Direction); // Shift char

#endif
