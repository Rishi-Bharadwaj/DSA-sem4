#include <stdio.h>
#include <stdlib.h>
#include<gmp.h>

char* multiply(char *a, char b, int n);
char* add(char* a, char* b);

int main() {
    char a[1000];
    char b[1000];
    char* result = "0"; // Initialize result

    printf("Enter the first number: ");
    scanf("%s", a);

    printf("Enter the second number: ");
    scanf("%s", b);

    int i = 0, len_a = 0, len_b = 0;
    while (a[i] != '\0') {
        len_a++;
        i++;
    }
    i = 0;
    while (b[i] != '\0') {
        len_b++;
        i++;
    }

    for (int k = len_b - 1; k >= 0; k--) {
        char* temp = multiply(a, b[k], len_a);
        result = add(result, temp);
        free(temp); // Free the memory allocated by multiply function
    }

    printf("Result: %s\n", result);

    // Free the memory allocated by add function
    free(result);

    return 0;
}

char* multiply(char *a, char b, int n) {
    char *product = (char *)malloc((n + 2) * sizeof(char));
    for (int i = 0; i < n + 2; i++) {
        product[i] = '0';
    }

    int carry = 0;
    int i = n - 1;

    while (i >= 0) {
        int x = (b - '0') * (a[i] - '0') + carry;
        carry = x / 10;
        int digit = x % 10;
        product[i + 1] = digit + '0';
        i--;
    }

    if (carry >= 1) {
        product[0] = carry + '0';
    } else {
        for (i = 0; i <= n - 1; i++) {
            product[i] = product[i + 1];
        }
    }

    product[n] = '\0';
    return product;
}

char* add(char* a, char* b) {
    char* sum = (char*)malloc(1001 * sizeof(char));

    int i = 0, len_a = 0, len_b = 0;
    while (a[i] != '\0') {
        len_a++;
        i++;
    }
    i = 0;
    while (b[i] != '\0') {
        len_b++;
        i++;
    }

    int j = len_b - 1;
    i = len_a - 1;
    int carry = 0;

    while (j >= 0) {
        int x = a[i] - '0' + b[j] - '0' + carry;
        if (x >= 10) {
            x = x - 10;
            carry = 1;
        } else {
            carry = 0;
        }
        sum[i] = x + '0';
        j--;
        i--;
    }

    while (i >= 0) {
        int x = a[i] - '0' + carry;
        if (x >= 10) {
            x = x - 10;
            carry = 1;
        } else {
            carry = 0;
        }
        sum[i] = x + '0';
        i--;
    }

    if (carry == 1) {
        for (int i = len_a - 1; i >= 0; i--) {
            sum[i + 1] = sum[i];
        }
        sum[0] = '1';
    }

    return sum;
}
