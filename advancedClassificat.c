#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int isPalindrome(int a)
{
    int count =0;
    double temp=(double)a;
    while((int)temp != 0)
    {
        count++;
        temp/=10;
    }
    temp*=10;
    for (int i = 0; i < count/2; i++)
    {
        if(a%10 != (int)temp)
        {
            return 0;//false
        }
        else
        {
            a=a/10;
            temp=temp-(int)temp;
            temp=temp*10;
        }
    }
    return 1;
}

int isArmstrong(int a)
{
    int count =0;
    int temp =a;
	int sum=0;
	while (temp != 0)
	{
        temp/=10;
        count++;
	}
    temp=a;
    while (temp!=0)
    {
        double ans=pow((double)(temp%10),(double)count);
        sum+=ans;
		temp/=10;
    }
    
	if(a==sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

