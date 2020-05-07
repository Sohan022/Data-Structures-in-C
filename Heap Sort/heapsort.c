#include<stdio.h>

int n;

void heapify(int arr[],int i,int n)
{
    int lc,rc,max;
    lc=2*i+1;
    rc=2*i+2;
    while(lc<=n)
    {
        if(lc==n)
            max=lc;
        else
            max=arr[lc]>arr[rc]?lc:rc;
        if(arr[max]<arr[i])
            break;
        int temp=arr[max];
        arr[max]=arr[i];
        arr[i]=temp;
        i=max;
        lc=2*max+1;
        rc=2*max+2;
    }
}

int delete(int arr[])
{
	if(n==0)
	return -1;
	arr[0]=arr[n-1];
	n=n-2;
    heapify(arr,0,n);
    n++;
	return 0;
}

void heapsort(int arr[],int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		printf("%d  ",arr[0]);
        delete(arr);		
	}
}

void print(int arr[])
{
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
}

int main()
{
	int arr[100],i,m;
	printf("enter the size of array = ");
	scanf("%d",&n);
	printf("enter the element\n");
	for(i=0;i<n;i++)
	    scanf("%d",&arr[i]);
	for(i=(n-2)/2;i>=0;i--)
    {
        heapify(arr,i,n-1);
    }
    m=n;
    printf("the output of heapsort is\n");
    heapsort(arr,m);
    return 0;
}
