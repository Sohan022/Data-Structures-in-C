#include<stdio.h>
int front=0,rear=0;

void heapify(int arr[],int i)
{
    int lc,rc,max;
    lc=2*i+1;
    rc=2*i+2;
    while(lc<=rear)
    {
        if(lc==rear)
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

int insert(int arr[],int a)
{
	if(rear==100)
	    return -1;
    arr[rear]=a;
    int i;
    for(i=(rear-1)/2;i>=0;i--)
    {
        heapify(arr,i);
    }
    return 1;
}

int delete(int arr[])
{
	if(rear==0)
	return -1;
	int x=arr[0];
	arr[0]=arr[rear-1];
	rear=rear-2;
    heapify(arr,0);
    rear++;
	return x;
}

int main()
{
    int arr[100];
    int m,a,x,y;
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.search the highest priority\n");
    printf("4.exit\n");
    while(1)
    {
        printf("enter the key for above operation = ");
        scanf("%d",&m);
        if(m==4)
            break;
        switch(m)
        {
             case 1:
                printf("enter the element = ");
                scanf("%d",&a);
                y=insert(arr,a);
                if(y==-1)
                {
                	printf("priority queue is overflow");
                	break;
				}
				rear++;
                break;
             case 2:
             	x=delete(arr);
                if(x==-1)
                {
                    printf("priority queue is underflow");
                    break;
                }
                printf("the highest priority element %d is deleted\n",x);
                break;
            case 3:
            	if(rear==0)
                {
                	printf("priority queue is null");
                	break;
				}
            	printf("the highest priority element is %d",arr[front]);
            	break;
        }
        printf("\n\n");
    }
    return 0;
}

