#include <stdio.h>

double square_root(int N) {
    double low = 0.0, high = N;
    double epsilon = 1e-7;  // Precision limit

    while (high - low > epsilon) {
        double mid = (low + high) / 2;
        double square = mid * mid;

        if (square > N) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return low;
}

int main() {
    int N;
    scanf("%d", &N);

    double result = square_root(N);

    // Print the result with 6 digits after the decimal point
    printf("%.6lf\n", result);

    return 0;
}
