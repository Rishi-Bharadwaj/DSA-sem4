#include <stdio.h>
#include <math.h>

int karatsuba(int x, int y);

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    int result = karatsuba(x, y);

    printf("Result: %d\n", result);

    return 0;
}

int karatsuba(int x, int y) {
    // Base case
    if (x < 10 && y < 10) {
        return x * y;
    }

    int n = fmax(log10(x) + 1, log10(y) + 1);
    int m = ceil(n / 2.0);

    int x_H = x / (int)pow(10, m);
    int x_L = x % (int)pow(10, m);

    int y_H = y / (int)pow(10, m);
    int y_L = y % (int)pow(10, m);

    // Recursive steps
    int a = karatsuba(x_H, y_H);
    int d = karatsuba(x_L, y_L);
    int e = karatsuba(x_H + x_L, y_H + y_L) - a - d;

    return a * (int)pow(10, 2 * m) + e * (int)pow(10, m) + d;
}
