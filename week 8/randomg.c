#include <stdio.h>
#include <stdlib.h>

void exchange(int *A, int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition(int *A, int p, int r) {
    int x = A[r];
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

int randomized_partition(int *A, int p, int r) {
    int i = rand() % (r - p + 1) + p;
    exchange(A, r, i);
    return partition(A, p, r);
}

int randomized_select(int *A, int p, int r, int i) {
    if (p == r)
        return A[p];

    int q = randomized_partition(A, p, r);
    int k = q - p + 1;

    if (i == k)
        return A[q];
    else if (i < k)
        return randomized_select(A, p, q - 1, i);
    else
        return randomized_select(A, q + 1, r, i - k);
}

void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int x = randomized_select(arr,0,n-1,n+1-k);
    printf("%d",x);
}
