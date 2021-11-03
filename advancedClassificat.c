#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int isPalindrome(int a)
{
    int temp=revers(a);
    if(a==temp)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int revers(int a)
{  
    int temp =0;
    while(a != 0)
    {
        temp*=10;
        temp+=a%10;
    }
    return temp;
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

