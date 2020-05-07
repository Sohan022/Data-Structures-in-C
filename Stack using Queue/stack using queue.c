#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int i;
	struct node *next;
}queue;

int enqueue(queue **front, queue **rear,int a)
{
	queue *t=(queue *)malloc(sizeof(queue));
	if(t=='\0')
	{
		return -1;
	}
	t->i=a;
	t->next='\0';
	if(*rear=='\0')
	{
		*front=t;
		*rear=t;
		return 1;
	}
	(*rear)->next=t;
	*rear=t;
	return 1;
}
int dequeue(queue **front,queue **rear)

{
	if(*front=='\0')
	{
		return -1;
	}
	queue *t=*front;
	if(*front==*rear)
	*rear='\0';
	*front=(*front)->next;
	free(t);
	return 1;
}
int main()
{
    int n,a,b,c;
    queue *front='\0',*rear='\0';
    queue *front1='\0',*rear1='\0';
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
                b=enqueue(&front1,&rear1,a);
                while(front)
                {
                	enqueue(&front1,&rear1,front->i);
                	dequeue(&front,&rear);
				}
				front=front1;
				rear=rear1;
				front1='\0';
				rear1='\0';
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
            	if(front=='\0')
            	    printf("no element in the stack");
            	else
                   printf("peek of the element is %d",front->i);
                break;
        }
        printf("\n\n");
    }
    return 0;
}
