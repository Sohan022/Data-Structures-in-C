#include<stdio.h>
int fun(int a[],int low,int high)
{
	if(low>high)
	return -1;
	if(low==high)
    {
    	return low;
	}
	int mid=(low+high)/2;
	if(mid%2==0)
	{
		if(a[mid]==a[mid+1])
		fun(a,mid+2,high);
		else
		fun(a,low,mid);
	}
	else
	{
		if(a[mid]==a[mid-1])
		fun(a,mid+1,high);
		else
		fun(a,low,mid-1);
	}
}
int main()
{
	int a[100],c,n=0,m;
	printf("enter the elements, if you do not want to enter then press -1\n");
	while(1)
	{
		scanf("%d",&m);
		if(m==-1)
		break;
		a[n]=m;
		n++;
	}
	c=fun(a,0,n-1);
	if(c==-1)
	printf("invalid input\n");
	else
	printf("element is %d",a[c]);
	return 0;
}
