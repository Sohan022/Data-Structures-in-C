#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int i;
	struct node *next;
}cqueue;
cqueue *front='\0',*rear='\0';
int enqueue(int a)
{
    cqueue *t=(cqueue *)malloc(sizeof(cqueue));
    t->i=a;
    if(t=='\0')
	return -1; 
    if(front=='\0')
    {
       front=t;
       t->next=front;
       rear=front;
       return 1;
    }
    rear->next=t;
    rear=t;
    rear->next=front;
    return 1;
}
int dequeue()
{
	if(front=='\0')
	return -1;
	if(front==rear)
	{
		free(front);
		front='\0';
		rear='\0';
		return 1;
	}
	cqueue *p=front;
	front=front->next;
	free(p);
	rear->next=front;
	return 1;
}
int count()
{
	if(front=='\0')
	{
		return 0;
	}
	int c=1;
	cqueue *p=front;
	while(p!=rear)
	{
		p=p->next;
		c++; 
	}
	return c;
}
int main()
{
	int a,m,b,c,d;
	printf("1.insert an element to the queue\n2.delete an element from the queue\n3.peek an element from the queue\n4.count the element in the queue\n5.exit\n");
	while(1)
	{
		printf("press 1 t0 5 for above operation\n");
		scanf("%d",&m);
		if(m==5)
		break;
		switch(m)
		{
			case 1:
				printf("enter the element which you want to insert = ");
				scanf("%d",&a);
				b=enqueue(a);
				if(b==-1)
				printf("overflow");
				if(b==1)
				printf("element is inserted");
				break;
			case 2:
				c=dequeue();
				if(c==-1)
				printf("underflow");
				if(c==1)
				printf("element is deleted");
				break;
			case 3:
				if(front=='\0')
				printf("there is no element");
				else
				printf("peek of the element is %d",front->i);
				break;
			case 4:
				d=count();
				printf("number of element in the queue is %d",d);
				break;
		}
		printf("\n\n");
	}
	return 0;
}

