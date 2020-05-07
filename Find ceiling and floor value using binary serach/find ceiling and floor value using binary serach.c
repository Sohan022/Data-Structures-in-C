#include<stdio.h>
#include<stdlib.h>
int binary_search(int a[],int low,int high,int k)
{
	if(low<=high){
	int mid=(low+high)/2;
	if(k==a[mid])
	return mid;
	else
	{
		if(k>a[mid])
		binary_search(a,mid+1,high,k);
		else
		binary_search(a,low,mid-1,k);
	}
}
else
return low;
}
int main()
{
	int x,n,i=0,a[100],m;
	printf("enter the element, if do not want to enter the press -1\n");
	while(1)
	{
		scanf("%d",&m);
		if(m==-1)
		break;
		else
		a[i]=m;
		i++;
	}
	printf("enter the element X = ");
	scanf("%d",&x);
	if(x>a[i-1])
	{
		printf("the greatest element smaller than or equal to x = does not exist\n");
		printf("the smallest element in array greater than or equal to x = %d\n",a[i-1]);
	}
	else
	{
		if(x<a[0])
		{
			printf("the greatest element smaller than or equal to x = %d\n",a[0]);
		    printf("the smallest element in array greater than or equal to x = does not exist\n");
		}
	else{
	n=binary_search(a,0,i-1,x);
	if(a[n]==x)
	{
		printf("the greatest element smaller than or equal to x = %d\n",a[n]);
		printf("the smallest element in array greater than or equal to x = %d\n",a[n]);
	}
	else
	{
		printf("the greatest element smaller than or equal to x = %d\n",a[n]);
		printf("the smallest element in array greater than or equal to x = %d\n",a[n-1]);
	}
    }
}
	return 0;
}
