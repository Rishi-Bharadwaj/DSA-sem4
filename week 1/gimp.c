#include <stdio.h>
#include <gmp.h>

int main() {
    // Initialize GMP integers
    mpz_t num1, num2, result;

    // Initialize GMP integers
    mpz_init(num1);
    mpz_init(num2);
    mpz_init(result);

    // Input the two numbers
    gmp_scanf("%Zd", num1);
    gmp_scanf("%Zd", num2);

    // Multiply the numbers
    mpz_mul(result, num1, num2);

    // Output the result
    gmp_printf("Product: %Zd\n", result);

    // Free the allocated memory
    mpz_clear(num1);
    mpz_clear(num2);
    mpz_clear(result);

    return 0;
}
