#include<stdio.h>
void convert(long long int n)
{
    long long int c;
    if(n>=1000000000000)
    {
        c=n/1000000000000;
        convert(c);
        printf(" trillion");
        if(n-1000000000000*c)
        {
            printf(" ");
            convert(n-1000000000000*c);
        }
    }
    else if(n>=1000000000)
    {
        c=n/1000000000;
        convert(c);
        printf(" billion");
        if(n-1000000000*c)
        {
            printf(" ");
            convert(n-1000000000*c);
        }
    }
    else if(n>=1000000)
    {
        c=n/1000000;
        convert(c);
        printf(" million");
        if(n-1000000*c)
        {
            printf(" ");
            convert(n-1000000*c);
        }
    }
    else if(n>=1000)
    {
        c=n/1000;
        convert(c);
        printf(" thousand");
        if(n-1000*c)
        {
            printf(" ");
            convert(n-1000*c);
        }
    }
    else if(n>=100)
    {
        c=n/100;
        convert(c);
        printf(" hundred");
        if(n-100*c)
        {
            printf(" ");
            convert(n-100*c);
        }
    }
    else if(n>=90)
    {
        printf("ninety");
        if(n>90){
            printf(" ");
        convert(n-90);
    }}
    else if(n>=80)
    {
        printf("eighty");
        if(n>80){

        printf(" ");
        convert(n-80);
    }}
    else if(n>=70)
    {
        printf("seventy");
        if(n>70){
             printf(" ");
        convert(n-70);
    }}
    else if(n>=60)
    {
        printf("sixty");
        if(n>60){
             printf(" ");
        convert(n-60);
    }}
    else if(n>=50)
    {
        printf("fifty");
        if(n>50){
             printf(" ");
        convert(n-50);
    }}
    else if(n>=40)
    {
        printf("forty");
        if(n>40){
         printf(" ");
        convert(n-40);
    }}
    else if(n>=30)
    {
        printf("thirty");
        if(n>30){
             printf(" ");
        convert(n-30);
    }}
    else if(n>=20)
    {
        printf("twenty");
        if(n>20){
            printf(" ");
            convert(n-20);
        }
    }
    else if(n==19)
    {
        printf("nineteen");
    }
     else if(n==18)
    {
        printf("eighteen");
    }
     else if(n==17)
    {
        printf("seventeen");
    }
     else if(n==16)
    {
        printf("sixteen");
    }
     else if(n==15)
    {
        printf("fifteen");
    }
     else if(n==14)
    {
        printf("fourteen");
    }

     else if(n==13)
    {
        printf("thirteen");
    }
     else if(n==12)
    {
        printf("twelve");
    }
     else if(n==11)
    {
        printf("eleven");
    }
     else if(n==10)
    {
        printf("ten");
    }
    else if(n==9)
    {
        printf("nine");
    }
    else if(n==8)
    {
        printf("eight");
    }
    else if(n==7)
    {
        printf("seven");
    }
    else if(n==6)
    {
        printf("six");
    }
    else if(n==5)
    {
        printf("five");
    }
    else if(n==4)
    {
        printf("four");
    }
    else if(n==3)
    {
        printf("three");
    }
    else if(n==2)
    {
        printf("two");
    }
    else if(n==1)
    {
        printf("one");
    }
    else if(n==0)
    {
        printf("zero");
    }


}

void main()
{
    int n;
    //scanf("%d",&n);
    convert(193);
}