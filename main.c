#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int main()
{
    // printf("enter two numbers \n");
    int a;
    int b;
    while ((scanf ("%d%d" , &a , &b) != 2) || (a < 0) || (b < 0))
    {
        char temp;
        scanf ("%c" , &temp);
        printf ("ERROR! \n");
        printf("enter two positive numbers \n");
    }
    int max =fmax(a,b);
    int min =fmin(a,b);

    printf("The Armstrong numbers are:");
    for(int i = min; i <= max; i++)
    {
        if(isArmstrong(i)==1)
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("The Palindromes are:");
    for(int i = min; i <= max; i++)
    {
        if(isPalindrome(i)==1)
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("The Prime numbers are:");
    for(int i = min; i <= max; i++)
    {
        if(isPrime(i)==1)
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("The Strong numbers are:");
    for(int i = min; i <= max; i++)
    {
        if(isStrong(i)==1)
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}