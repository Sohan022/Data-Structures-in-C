#include<stdio.h>
int q[100];
int enqueue(int *front,int *rear, int a)
{
	if(*rear==100)
	{
		return -1;
	}
	q[*rear]=a;
	*rear=*rear+1;
	return 1;
}
int dequeue(int *front,int *rear)
{
	if(*rear==*front)
	{
		return -1;
	}
	*front=*front+1;
	return 1;
}
int main()
{
    int n,a,b,c;
    int front=0,rear=0;
    printf("1.push an element to queue\n2.pop an element from queue\n3.peek an element from queue\n4.exit\n");
    while(1)
    {
	    printf("enter the key from 1 to 4 for above operation\n");
        scanf("%d",&n);
        if(n==4)
        {
        	break;
		}
        switch(n)
        {
            case 1:
                printf("enter the element which you want to push = ");
                scanf("%d",&a);
                b=enqueue(&front,&rear,a);
                if(b==-1)
                {
                	printf("overflow");
				}
				if(b==1)
				{
					printf("element is pushed");
				}
                break;
            case 2:
            	c=dequeue(&front,&rear);
            	if(c==-1)
				{
					printf("underflow");
				}
				if(c==1)
				{
					printf("element is poped out");
				}
            	break;
            case 3:
            	if(front==rear)
            	    printf("no element in the stack");
            	else
                   printf("peek of the element is %d",q[front]);
                break;
        }
        printf("\n\n");
    }
    return 0;
}
