#include<stdio.h>
#include<stdlib.h>
typedef struct node {
         int i;
         struct node *next;
}node;
node *insert(node *head,int a,int j)
{
	node *p,*t=(node *)malloc(sizeof(node));
	t->i=a;
	node *s;
	if(head=='\0')
	{
	    if(j==0)
        {
		    t->next='\0';
    	    head=t;
    	    return head;
        }
        else
        {
            t->next=t;
            head=t;
	        return head;
        }
	}
	else
	{
		p=head;
		while(p->next)
		{
			p=p->next;
		}
		p->next=t;
		s=head;
		int c=1;
		if(j==0)
        {
		   t->next='\0';
        }
        else
        {
            while(c!=j)
            {
                s=s->next;
                c++;
            }
            t->next=s;
        }
		return head;
	}
}
int check_loop(node *head)
{
   node *s=head,*f=head;
   while(1)
   {
       s=s->next;
       f=f->next->next;
       if((f=='\0')||(s=='\0'))
       {
           printf("there is no loop\n");
           return -1;
       }
       if(f==s)
       {
           printf("there is a loop\n");
           return f->i;
       }
   }
}
void count(node *head,int a)
{
    node *t=head;
    int c=0;
    while(t)
    {
        if(t->i==a)
        {
            break;
        }
        t=t->next;
    }
    do
    {
        t=t->next;
        ++c;
    }
    while(t->i!=a);
    printf("%d is the length of loop\n",c);
}
int main()
{
    node *head='\0';
    int n,a,j,r;
    while(1)
    {
        printf("enter the element which you want to insert = ");
        scanf("%d",&a);
        printf("if you want to connect node anywhere press that node number otherwise 0\n");
        scanf("%d",&j);
        head=insert(head,a,j);
        printf("inserted and connected\n");
        printf("if you do not want to insert press -1 otherwise press 1\n");
        scanf("%d",&n);
        printf("\n");
        if(n==-1)
        {
            break;
        }
    }
    r=check_loop(head);
    if(r==-1)
        printf("\n");
    else
    {
        count(head,r);
    }
    return 0;
}
