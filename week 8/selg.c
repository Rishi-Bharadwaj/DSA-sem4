#include <stdio.h>

void exchange(int *A, int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition(int *A, int p, int r, int x) {
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            exchange(A, i, j);
        }
    }
    exchange(A, i + 1, r);
    return i + 1;
}

int select(int *A, int p, int r, int i) {
    while ((r - p + 1) % 5 != 0) {
        for (int j = p + 1; j <= r; j++) {
            if (A[p] > A[j]) {
                exchange(A, p, j);
            }
        }
    }

    if (i == 1)
        return A[p];

    p = p + 1;
    i = i - 1;
    int g = (r - p + 1) / 5;

    for (int j = p; j <= p + g - 1; j++) {
        // sort each group
        // You can implement your sorting algorithm here
        // For simplicity, let's assume a simple bubble sort
        for (int k = j; k <= p + g - 1; k++) {
            if (A[j] > A[k]) {
                exchange(A, j, k);
            }
        }
    }

    int x = select(A, p + 2 * g, p + 3 * g - 1, (g + 1) / 2);
    int q = partition(A, p, r, x);

    int k = q - p + 1;
    if (i == k)
        return A[q];
    else if (i < k)
        return select(A, p, q - 1, i);
    else
        return select(A, q + 1, r, i - k);
}

int main() {
    int A[] = {7, 10, 4, 3, 20, 15, 8, 2, 1, 11};
    int n = sizeof(A) / sizeof(A[0]);
    int i = 5; // find the 5th smallest element

    int result = select(A, 0, n - 1, i);
    printf("The %dth smallest element is %d\n", i, result);

    return 0;
}
