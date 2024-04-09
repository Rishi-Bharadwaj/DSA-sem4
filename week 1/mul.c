#include <stdio.h>
#include <stdlib.h>

// Function to multiply two strings
char* multiplyStrings(const char* num1, const char* num2);

int main() {
    // Input the two numbers as strings
    char num1[1010];
    char num2[1010];

    printf("Enter the first number: ");
    scanf("%s", num1);

    printf("Enter the second number: ");
    scanf("%s", num2);

    // Call the function to multiply the two numbers
    char* result = multiplyStrings(num1, num2);

    // Output the result
    printf("Product: %s\n", result);

    // Free the memory allocated by multiplyStrings function
    free(result);

    return 0;
}

// Function to multiply two strings
char* multiplyStrings(const char* num1, const char* num2) {
    // Calculate the length of the input numbers
    int len1 = 0, len2 = 0;
    while (num1[len1] != '\0') {
        len1++;
    }
    while (num2[len2] != '\0') {
        len2++;
    }

    // Allocate memory for the product
    char* product = (char*)malloc((len1 + len2 + 1) * sizeof(char));

    // Initialize product with '0'
    for (int i = 0; i < len1 + len2; i++) {
        product[i] = '0';
    }
    product[len1 + len2] = '\0';

    // Multiply the numbers
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;

        for (int j = len2 - 1; j >= 0; j--) {
            int temp = (num1[i] - '0') * (num2[j] - '0') + (product[i + j + 1] - '0') + carry;
            product[i + j + 1] = temp % 10 + '0';
            carry = temp / 10;
        }

        product[i] += carry;  // Add carry to the current position
    }

    // Remove leading zeroes
    int i = 0;
    while (product[i] == '0') {
        i++;
    }

    // Shift the result to the beginning of the array
    for (int j = 0; i + j <= len1 + len2; j++) {
        product[j] = product[i + j];
    }

    // Allocate memory for the final result
    char* result = (char*)malloc((len1 + len2 - i + 1) * sizeof(char));
    for (int j = 0; j <= len1 + len2 - i; j++) {
        result[j] = product[j];
    }

    return result;
}
