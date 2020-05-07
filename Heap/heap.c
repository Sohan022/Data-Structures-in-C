#include<stdio.h>
int n=0;

void heapify(int arr[],int i)
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

void insert(int arr[],int a)
{
    arr[n]=a;
    int i;
    for(i=(n-1)/2;i>=0;i--)
    {
        heapify(arr,i);
    }
}

int delete(int arr[])
{
	if(n==0)
	return -1;
	arr[0]=arr[n-1];
	n=n-2;
    heapify(arr,0);
    n++;
	return 0;
}

void print(int arr[])
{
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
}

int main()
{
    int arr[100];
    int m,a,x;
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.exit\n");
    while(1)
    {
        printf("enter the key for above operation = ");
        scanf("%d",&m);
        if(m==3)
            break;
        switch(m)
        {
             case 1:
                printf("enter the element = ");
                scanf("%d",&a);
                insert(arr,a);
                n++;
                print(arr);
                break;
             case 2:
             	x=delete(arr);
                if(x==-1)
                {
                    printf("heap is empty");
                    break;
                }
                printf("the output after deleting the highest priority element\n");
                print(arr);
                break;
        }
        printf("\n\n");
    }

return 0;
}

