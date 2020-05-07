#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int i;
    struct node *next;
}node;
int push(node **top,int a)
{
	node *t=(node *)malloc(sizeof(node));
	if(t=='\0')
	{
		return -1;
	}
	t->i=a;
	t->next=*top;
	*top=t;
	return 1;
}
int pop(node **top)
{
	if(*top=='\0')
	{
		return -1;
	}
    node *t=*top;
    *top=(*top)->next;
    free(t);
    return 1;
}
int main()
{
    node *top='\0',*top1='\0',*l;
    int n,a,b,c;
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
                b=push(&top,a);
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
            	while(top)
            	{
            		push(&top1,top->i);
            		pop(&top);
				}
            	c=pop(&top1);
            	while(top1)
            	{
            		push(&top,top1->i);
            		pop(&top1);
				}
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
            	if(top=='\0')
            	   {
					 printf("no element in the stack");
            	    break;}
            	else
                {
                	l=top;
                	while(l->next)
                	{
                		l=l->next;
					}
				}
                printf("peek of the element is %d",l->i);
                break;
        }
        printf("\n\n");
    }
    return 0;
}

