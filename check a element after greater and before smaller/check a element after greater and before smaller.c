#include<stdio.h>
int check(int a[],int n)
{
	int min,i,max[50];
	max[0]=a[0];
	for(i=1;i<n;i++)
	{
		max[i]=max[i-1]>a[i-1]?max[i-1]:a[i-1];
	}
	min=a[n-1];
	for(i=n-1;i>=0;i--)
	{
		if (max[i] < a[i] && min > a[i]) 
        return i;  
        min=min>a[i]?a[i]:min;
    } 
	return -1;
}
int main()
{
	int a[100],n=0,i,m,x,c;
	printf("enter the element, if do not want to enter the press -1\n");
	while(1)
	{
		scanf("%d",&m);
		if(m==-1)
		break;
		else
		a[n]=m;
		n++;
	}
	c=check(a,n);
	if(c==-1)
	{
		printf("not found\n");
	}
	else
	printf("index position is %d",c);
	return 0;
}
