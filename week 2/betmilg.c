#include <stdio.h>

int max_subarray_sum(int arr[], int n) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];

    for (int i = 1; i < n; i++) {
        max_ending_here = (arr[i] > max_ending_here + arr[i]) ? arr[i] : max_ending_here + arr[i];
        max_so_far = (max_so_far > max_ending_here) ? max_so_far : max_ending_here;
    }

    return max_so_far;
}

int main() {
    int N;
    scanf("%d", &N);

    int revenues[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &revenues[i]);
    }

    int result = max_subarray_sum(revenues, N);
    printf("%d\n", result);

    return 0;
}
