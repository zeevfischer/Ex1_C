#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int isPalindrome(int a)
{
	if(a==0)
	{
		return 1;
	}
	else
	{
		int count =0;
		double temp=(double)a;
		while((int)temp != 0)
		{
			count++;
			temp/=10;
		}
		temp*=10;
		if(count ==1)
		{
			return 1;//true
		}
		if(count==2 && (a%10 == (int)temp))
		{
			return 1;
		}
		if(a%10 != (int)temp)
		{
			return 0;//false
		}
		else
		{
			temp=temp-(int)temp;
			for(int i = 1 ;i < count-1;i++)
			{
				temp*=10;
			}
			return isPalindrome((int)temp);
		}
	}
}
int help(int a,int sum,int count)
{
	if(a != 0)
	{
		sum=pow((a%10), count);
		sum+=help(a/10,sum,count);
	}
	if(a==0)
	{
		return 0;
	}
	else
	{
		return sum;
	}
}
int isArmstrong(int a)
{
	int count =0;
    int temp =a;
	while (temp != 0)
	{
        temp/=10;
        count++;
	}
	int sum=help(a,0,count);
	if(a==sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}