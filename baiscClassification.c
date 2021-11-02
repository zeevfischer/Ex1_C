#include <stdio.h>
#include "NumClass.h"

int isPrime(int a)
{
    if(a==1 || (a>2 && a%2==0))
    {
        return 0;
    }
    for(int i = 2 ;i < a/2;i++)
    {
        if(a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int atzeret(int a)
{
    int sum=1;
    if(a==1 || a==0)
    {
        return 1;
    }
    else
    {
        for(int i =1; i <= a;i++)
        {
            sum*=i;
        }
    }
    return sum;
} 
int isStrong(int a)
{
    int save=a;
    int sum=0;
    while(a != 0)
    {
        int temp = a % 10;
        sum+=atzeret(temp);
        a=a/10;
    }
    if(save==sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}