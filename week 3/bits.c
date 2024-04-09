#include <stdio.h>

void printBinary(int num) {
    int size = sizeof(int) * 8; // Size of integer in bits

    for (int i = size - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
        
        if (i % 4 == 0) {
            // Add a space every 4 bits for better readability
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("Binary representation: ");
    printBinary(number);

    return 0;
}
