#include <stdio.h>
#include <gmp.h>

void main()
{
    mpz_t n;
    mpz_t p;
    mpz_t m;
    mpz_init(n);
    mpz_init(p);
    mpz_init(m);
    mpz_t result;
    mpz_init(result);
    gmp_scanf("%Zd",n);
    gmp_scanf("%Zd",m);
    mpz_set_ui(p,1);
    mpz_t mul;
    mpz_init(mul);
    mpz_mul(mul,p,n);
    mpz_mod(result,mul,m);
    while(mpz_cmp_ui(result,1)!=0)
    {
        mpz_add_ui(p,p,1);
        mpz_mul(mul,p,n);
        mpz_mod(result,mul,m);
    }
    gmp_printf("%Zd",p);
    mpz_clears(m,n,result,p,mul);
}