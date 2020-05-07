#include<stdio.h>
int s[100];
int push(int *top,int a)
{
	if (*top==99)
	{
        return -1;
	}
	else
	{
		s[++*top]=a;
		return 1;
	}
}
int pop(int *top)
{
	if(*top==-1)
	{
		return -1;
	}
	else
	{
		*top=*top-1;
		return 1;
	}
}
int main()
{
    int top=-1;
    int n,a,b,c;
    printf("1.push an element to stack\n2.pop an element from stack\n3.peek an element from stack\n4.exit\n");
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
            	c=pop(&top);
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
            	if(top==-1)
            	    printf("no element in the stack");
            	else
                   printf("peek of the element is %d",s[top]);
                break;
            
        }
        printf("\n\n");
    }
    return 0;
}
