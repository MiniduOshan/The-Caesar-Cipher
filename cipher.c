#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cipher.h"

// create queue structure
void CreateQueue(Queue *q) {
    q->count= 0;
    q->front= 0;
    q->rear = -1;
}

// Checks the queue is full
int IsFull(const Queue *q){
    return q->count== MAXQUEUE;
}

// Adds a new character(x)
void Append(Queue *q,QElement x){
    if (IsFull(q))
    {
        printf("Queue is full.Max %d characters allowed.\n", MAXQUEUE);
        exit(1); 
    }
    q->rear =(q->rear + 1)% MAXQUEUE;
    q->items[q->rear]= x;
    q->count++;
}

// initialize a queue with the uppercase
void ToAlphaQueue(Queue *q) {
    CreateQueue(q);
    for (char ch ='A'; ch<='Z'; ch++){
        Append(q, ch);
    }
}

// Finds index of characters separately
int FindQIndex(Queue *q, char target){
    for (int i = 0; i < MAXQUEUE; i++){
        int index = (q->front + i) % MAXQUEUE;
        if (q->items[index] == target){
            return index;
        }

    }
    return -1; // it mean not found
}

// Shifts a character to the right or left based on direction
char ShiftChar(Queue *q, char ch, int shift, int Direction){
    int index= FindQIndex(q, ch);
    if (index == -1) {
            return ch; // Return original character if it's not in the queue
    }

    int steps;

    if (Direction == 1){
        steps=shift%MAXQUEUE; // Right shift(1 mean right shift)
    }
    else {
        steps=(MAXQUEUE-(shift%MAXQUEUE))% MAXQUEUE; // Left shift(0 mean left shift)
    }

    int newIndex= (index + steps) % MAXQUEUE;
    return q->items[newIndex];
}

// Encrypts the message by shifting(for encrypt we shift characters to the right)
void Encrypt(char *message, int shift, char *output){
    Queue alphaQueue;
    ToAlphaQueue(&alphaQueue);

    int i = 0;
    while (message[i] !='\0'){
        if (isalpha(message[i])){
            char upper= toupper(message[i]);
            output[i]= ShiftChar(&alphaQueue, upper, shift,1);

        }else {
            output[i]= message[i]; // non-alphabet characters are unchanged
        }
        i++;
    }
    output[i]='\0'; // Null-terminate the output string
}

// Decrypts the message by shifting letters to the left
void Decrypt(char *message, int shift,char *output){
    Queue alphaQueue;
    ToAlphaQueue(&alphaQueue);

    int i = 0;
    while (message[i] !='\0'){
        if (isalpha(message[i])){
            char upper= toupper(message[i]);
            output[i]= ShiftChar(&alphaQueue, upper, shift,0);
        }
        else
        {
            output[i]= message[i]; // Non-alphabetic characters are still unchanged
        }
        i++;
    }
    output[i]='\0'; // Null-terminate the decrypted string
}
