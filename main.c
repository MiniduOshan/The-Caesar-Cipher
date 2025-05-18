#include <stdio.h>
#include <string.h>
#include "cipher.h"

int main() {
    char choice;
    char message[100];
    char output[100];
    int shift;
    char repeat;

    printf("Caesar Cipher - Encrypt or Decrypt\n");

    do {
        printf("\nEncryption (E) or Decryption (D)?: ");
        scanf(" %c", &choice);
        getchar(); // clear newline

        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';

        // Validate letter count
        int letterCount = 0;
        for (int i = 0; message[i] != '\0'; i++) {
            if ((message[i] >= 'A' && message[i] <= 'Z') || (message[i] >= 'a' && message[i] <= 'z')) {
                letterCount++;
            }
        }

        if (letterCount > MAXQUEUE) {
            printf("Error: Message contains more than %d letters.\n", MAXQUEUE);
        } else {
            printf("Enter shift key: ");
            scanf("%d", &shift);
            getchar();

            if (choice == 'E' || choice == 'e') {
                Encrypt(message, shift, output);
                printf("*****************************\n");
                printf("Encrypted Message: %s\n", output);
                printf("*****************************\n");
            } else if (choice == 'D' || choice == 'd') {
                Decrypt(message, shift, output);
                printf("*****************************\n");
                printf("Decrypted Message: %s\n", output);
                printf("*****************************\n");
            } else {
                printf("Invalid choice. Try again.\n");
            }
        }

        printf("\nRun again? (Y/N): ");
        scanf(" %c", &repeat);
        getchar();

    } while (repeat == 'Y' || repeat == 'y');

    printf("Goodbye!\n");
    return 0;
}
