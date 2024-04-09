#include <stdio.h>
#include <stdlib.h>

int isPrime(long long int num) {
    if (num < 2) {
        return 0; // Not a prime
    }
    for (long long int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not a prime
        }
    }
    return 1; // Prime
}

int main() {
    int n;
    scanf("%d", &n);

    long long int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    long long int result = 1;
    for (int i = 0; i < n; i++) {
        if (!isPrime(a[i])) {
            result = (result * a[i]) % 1000000007;
        }
    }

    if (result == 1) {
        result = -1;
    }

    printf("%lld", result);

    return 0;
}
