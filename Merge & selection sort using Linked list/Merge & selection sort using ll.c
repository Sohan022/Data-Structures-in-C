#include<stdio.h>
#include<time.h>
#include<stdlib.h>


typedef struct node{
	int i;
	int index;
	struct node *next;
}node;
node *insert(node *head,int a,int b)
{
	node *p,*t=(node *)malloc(sizeof(node));
	t->i=a;
	t->index=b;
	if(head=='\0')
	{
		t->next=head;
    	head=t;
	    return head;
	}
	else
	{
		p=head;
		while(p->next)
		{
			p=p->next;
		}
		p->next=t;
		t->next='\0';
		return head;
	}
}
void print(node *head)
{
	node *t=head;
	while(t)
	{
		printf("%d, index=%d\n",t->i,t->index);
		t=t->next;
	}
	return;
}
node *delete_ll(node *head)
{
    node *t;
    while(head)
    {
        t=head;
        head=head->next;
        t->next='\0';
        free(t);
    }
    return head;
}
void selection_sort(node *head)
{
	node *t=head,*min;
	int temp_data,temp_index;
	while(t)
	{
		min=t;
		node *p=t->next;
		while(p)
		{
			if((min->i)>(p->i))
			{
				min=p;
			}
			p=p->next;
		}
		temp_data=t->i;
		temp_index=t->index;
		t->i=min->i;
		t->index=min->index;
		min->i=temp_data;
		min->index=temp_index;
		t=t->next;
	}
	return;	
}
void middle(node *head,node **a,node **b)
{
    node *slow=head;
    node *fast=head->next;
    while(fast!='\0')
    {
    	fast=fast->next;
    	if(fast!=NULL)
    	{
    		slow=slow->next;
    		fast=fast->next;
		}
	}
	*a=head;
	*b=slow->next;
	slow->next='\0';
}
 node *merge(node *a,node *b)
{
	node *r='\0';
	if(a=='\0')
	return b;
	if(b=='\0')
	return a;
	if((a->i)<=(b->i))
	{
		r=a;
	    r->next=merge(a->next,b);
    }
    else
    {
    	r=b;
    	r->next=merge(a,b->next);
	}
    return r;
}
void merge_sort(node **heado)
{
	node *head=*heado;
	node *a,*b;
	if(head=='\0'||head->next=='\0')
	return;   
	middle(head,&a,&b);
	merge_sort(&a);
	merge_sort(&b);
	*heado=merge(a,b);
	return;
}
int main()
{
	int i,a,m,j=0;	
	node *head='\0';
	printf("1.selection sort\n2.merge sort\n3.exit\n");
	while(1)
	{
     	printf("press 1 to 3 for above operation = ");
	    scanf("%d",&m);
		if(m==3)
		break;
		printf("enter the element, if you do not want to insert then press -1\n");
		while(1)
		{
			scanf("%d",&a);
			if(a==-1)
			break;
			head=insert(head,a,j);
			j++;
		}
		print(head);
		printf("\noutput:\n");
		switch(m)
		{
			case 1:
				selection_sort(head);
				print(head);
				break;
			case 2:
				merge_sort(&head);
				print(head);
				break;
		}
		printf("\n\n");
		j=0;
      	head=delete_ll(head);
	}
	return 0;
}
