#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <ctype.h>      

#define QUEUE_SIZE 26   


typedef struct {
    char items[QUEUE_SIZE]; 
    int front;              
    int rear;               
} CircularQueue;

// Function to initialize the circular queue 


// check queue is empty


// check queue is full 


// add a character 


//remove and return a character 


// Caesar Cipher logic: shifts a character by 'key' positions 


// Encrypts 


// Decrypts


// Main function to get input, perform encryption and decryption
int main() {
    char text[1000]; // Input text
    int key;         // Shift value for Caesar cipher

    // Get user input
    

    // Get the shift key from user
    


    

    // Display
    printf("Original text: %s\n", text);

    encrypt(text, key);
    printf("Encrypted text: %s\n", text);

    decrypt(text, key);
    printf("Decrypted text: %s\n", text);

    return 0;
}
