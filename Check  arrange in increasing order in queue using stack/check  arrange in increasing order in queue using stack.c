#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int i;
	struct node *next;
}node;
node *top='\0';
void enqueue(node **front,node **rear,int a)
{
	node *t=(node *)malloc(sizeof(node));
	if(t=='\0')
	{
		return ;
	}
	t->i=a;
	t->next='\0';
	if(*rear=='\0')
	{
		*front=t;
		*rear=t;
		return;
	}
	(*rear)->next=t;
	*rear=t;
	return;
}
void dequeue(node **front,node **rear)
{
	if(*front=='\0')
	{
		return ;
	}
	node *t=*front;
	if(*front==*rear)
	*rear='\0';
	*front=(*front)->next;
	free(t);
	return ;
}
void push(int a)
{
	node *t=(node *)malloc(sizeof(node));
	if(t=='\0')
	{
		return;
	}
	t->i=a;
	t->next=top;
	top=t;
	return;
}
void pop()
{
	if(top=='\0')
	{
		return ;
	}
    node *t=top;
    top=top->next;
    t->next='\0';
    free(t);
    return;
}
int main()
{
	int a,j;
	node *front1='\0',*rear1='\0',*front2='\0',*rear2='\0';
	printf("enter the element in the queue and if you do not want to enter number press -1\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==-1)
		break;
		enqueue(&front1,&rear1,a);
	}
	j=1;
	while(1)
	{
	    if(front1!='\0')
        {
            if(front1->i==j)
            {
                enqueue(&front2,&rear2,j);
                dequeue(&front1,&rear1);
                j++;
            }
            else
            {
                if(top!='\0')
                {
                    if(top->i==j)
                    {
                        enqueue(&front2,&rear2,j);
                        pop();
                        j++;
                    }
                    else
                    {
                        if((front1=='\0')&&(top!='\0'))
                        {
                            printf("no\n");
                            break;
                        }
                        push(front1->i);
                        dequeue(&front1,&rear1);
                    }
                }
                else
                {
                    push(front1->i);
                    dequeue(&front1,&rear1);
                }
            }
	    }
		else
        {
		    if(top!='\0')
            {
                if(top->i==j)
                {
                    enqueue(&front2,&rear2,j);
                    pop();
                    j++;
                }
                else
                {
                    if((front1=='\0')&&(top!='\0'))
                    {
                        printf("output:no\n");
                        break;
                    }
                }
			}
		}
	    if((front1=='\0')&&(top=='\0'))
	    {
	    	printf("output:yes\n");
	    	break;
	    }
	}
	return 0;
}
