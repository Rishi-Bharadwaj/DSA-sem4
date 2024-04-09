#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t n;
    mpz_init(n);

    // Input using GMP
    gmp_scanf("%Zd", n);

    // Count the number of 1s in the binary representation of N
    int count=0;
    while(mpz_cmp_ui(n,0)>0){
        if(mpz_odd_p(n)){
            count++;
        }
        mpz_tdiv_q_2exp(n,n,1);
    }

    // Output using GMP
    printf("Number of 1s in binary representation: %d\n",count);

    mpz_clear(n);
    
    return 0;
}
