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

// dont need to use empty checker and serve function(not dequeuing)

// Check queue is full
int IsQueueFull(const Queue *q) {
    return q->count == MAXQUEUE;
}

/ Add an item to the rear
void Append(Queue *q, QueueElement x) {
    if (IsQueueFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->rear=(q->rear+1)%MAXQUEUE;
    q->items[q->rear]=x;              
    q->count++;
}

// Initialize the queue with the alphabet (A-Z)
void InitAlphabetQueue(Queue *q) {
    CreateQueue(q);
    for (char ch='A';ch<='Z';ch++) {
        Append(q,ch);
    }
}

// Encrypt single character
char EncryptChar(char ch, int shift) {
    if (!isalpha(ch)) return ch;
    ch = toupper(ch);
    return ((ch-'A'+shift+26)%26)+'A';
}

// Decrypt single character
char DecryptChar(char ch, int shift) {
    if (!isalpha(ch)) return ch;
    ch= toupper(ch);
    return ((ch-'A'-shift+26)%26)+'A';
}

// Encrypt an entire message
void EncryptMessage(char *message,int shift,char *output) {
    int i = 0;
    while (message[i] != '\0') {
        output[i]= EncryptChar(message[i], shift);
        i++;
    }
    output[i]= '\0';
}

// Decrypt an entire message
void DecryptMessage(char *message, int shift, char *output) {
    int i = 0;
    while (message[i] != '\0') {
        output[i]= DecryptChar(message[i], shift);
        i++;
    }
    output[i]= '\0';
}

