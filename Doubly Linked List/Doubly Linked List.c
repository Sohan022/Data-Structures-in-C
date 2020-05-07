#include<stdio.h>
#include<stdlib.h>
typedef struct node{
       int i;
       struct node *prev;
       struct node *next;
}node;
void menu()
{
    printf("0.Menu\n");
	printf("1.Insert an element at beginning of the list\n");
    printf("2.Insert an element at the end of the list\n");
	printf("3.Insert an element at a particular index position of the list\n");
    printf("4.Delete an element from the list given the key\n");
    printf("5.Delete an element from the list given the index of the node\n");
    printf("6.Search an element from the list given the key\n");
    printf("7.Delete the linked list\n");
    printf("8.Search an element from the list given the index of the node\n");
    printf("9.Get the nth node of the list\n");
    printf("10.Get the nth node from the end of the list\n");
    printf("11.Count the number of nodes of the list\n");
    printf("12.Get the middle element of the list\n");
    printf("13.Print the list\n");
    printf("14.Reverse the list\n");
    printf("-1 for exit\n");
}
void print(node *head)
{
	node *t=head;
	if(head=='\0')
    {
        printf("linked list is empty");
        return;
    }
	while(t)
	{
		printf("%d   ",t->i);
		t=t->next;
	}
}
node *insert_beg(node *head,int a)
{
    node *t=(node *)malloc(sizeof(node));
    t->i=a;
    t->prev='\0';
    t->next=head;
    head=t;
    return head;
}
node *insert_end(node *head,int a)
{
    node *p,*t=(node *)malloc(sizeof(node));
    t->i=a;
    t->next='\0';
    p=head;
    if(head=='\0')
    {
        t->prev='\0';
        head=t;
        return head;
    }
    while(p->next)
    {
       p=p->next;
    }
    t->prev=p;
    p->next=t;
    return head;
}
node *insert_index(node *head,int a,int j)
{
    node *p,*t=(node *)malloc(sizeof(node));
    t->i=a;
    p=head;
    int c=1;
    if(j==1)
    {
        t->next=head;
        t->prev='\0';
        if(head=='\0')
        {
            head=t;
            return head;
        }
        else
        {
            head->prev=t;
            head=t;
            return head;
        }
    }
    while(c!=j-1)
    {
        p=p->next;
        c++;
    }
    if(p->next=='\0')
    {
        t->next='\0';
        t->prev=p;
        p->next=t;
        return head;
    }
    t->next=p->next;
    p->next->prev=t;
    t->prev=p;
    p->next=t;
    return head;
}
node *delete_key(node *head,int a)
{
    node *p='\0',*t=head;
    if(t->next=='\0'&&t->i==a)
    {
        head='\0';
        free(t);
        return head;
    }
    else
    {
        while(t->i!=a)
        {
           p=t;
           t=t->next;
        }
        if(t->next=='\0')
        {
            p->next='\0';
            free(t);
            return head;
        }
        else
        {
            t->next->prev=p;
            p->next=t->next;
            free(t);
            return head;
        }
    }
}
node *delete_index(node *head,int a)
{
    node *p='\0',*t=head;
    int c=1;
    while(c!=a)
    {
        p=t;
        t=t->next;
        c++;
    }
    if(c==1)
    {
        if(t->next=='\0')
        {
            free(t);
            head='\0';
            return head;
        }
        else
        {
            head=t->next;
            free(t);
            return head;
        }
    }
    if(t->next=='\0')
    {
        p->next='\0';
        free(t);
        return head;
    }
    t->next->prev=p;
    p->next=t->next;
    free(t);
    return head;
}
void search_key(node *head,int a)
{
    node *t=head;
    while(t)
    {
        if(t->i==a)
        {
            printf("%d is found",a);
            return;
        }
        t=t->next;
    }
    if(t=='\0')
    {
        printf("%d is not found",a);
    }
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
    printf("entire linked list has deleted");
    return head;
}
void search_index(node *head,int a)
{
    node *t=head;
    int c=1;
    while(c!=a)
    {
        t=t->next;
        c++;
    }
    if(c==a)
    {
        printf("element %d is found at index %d",t->i,a);
    }
    else
    {
        printf("index %d is not found");
    }
}
void getnode_beg(node *head,int a)
{
    node *t=head;
    int c=1;
    while(c!=a)
    {
        t=t->next;
        c++;
    }
    if(c==a)
    {
        printf("element %d is found at node %d",t->i,a);
    }
    else
    {
        printf("node %d is not found");
    }
}
void getnode_end(node *head,int a)
{
    int d,c=0,e=1;
    node *t=head;
    while(t)
    {
        t=t->next;
        c++;
    }
    d=c-a+1;
    t=head;
    while(e!=d)
    {
        t=t->next;
        e++;
    }
    printf("%d is the element from %d node from end",t->i,a);
}
void count(node *head)
{
    int c=0;
    node *t=head;
    while(t)
    {
        t=t->next;
        c++;
    }
    printf("%d node in linked list",c);
}
void middle(node *head)
{
    int c=0,d,e=1;
    node *t=head;
    while(t)
    {
        t=t->next;
        c++;
    }
    d=c/2;
    t=head;
    while(e!=d+1)
    {
         t=t->next;
         e++;
    }
    printf("%d is the element of the middle node",t->i);
}
node *reverse(node *head)
{
    node *s=head,*p='\0',*t=head;
    while(t)
    {
        t=t->next;
        head->next=p;
        s->prev=t;
        s=t;
        p=head;
        head=t;
    }
    head=p;
    return head;
}
int main()
{
     node *head='\0';
     int n,a,j;
     menu();
     while(1)
     {
        printf("press -1 to 14 for operation in doubly linked list\n");
        scanf("%d",&n);
        if(n==-1)
        {
        	break;
	    }
    	switch(n)
        {
        	case 0:
        		menu();
        		break;
        	case 1:
        		printf("enter the value which you want insert = ");
        		scanf("%d",&a);
        		head=insert_beg(head,a);
        		printf("inserted");
        		break;
        	case 2:
        		printf("enter the value which you want to insert = ");
        		scanf("%d",&a);
        		head=insert_end(head,a);
        		printf("inserted");
        		break;
        	case 3:
        	    printf("enter the index where you want to insert = ");
        	    scanf("%d",&j);
        	    printf("enter the value which you want to insert = ");
        	    scanf("%d",&a);
        	    head=insert_index(head,a,j);
        	    printf("inserted");
        		break;
            case 4:
                printf("enter the key which you want to delete = ");
                scanf("%d",&a);
                head=delete_key(head,a);
                printf("deleted");
                break;
            case 5:
                printf("enter the index which you want to delete = ");
                scanf("%d",&a);
                head=delete_index(head,a);
                printf("deleted");
                break;
            case 6:
                printf("enter the element which you want to search = ");
                scanf("%d",&a);
                search_key(head,a);
                break;
            case 7:
                head=delete_ll(head);
                break;
            case 8:
                printf("enter the index which you want to search = ");
                scanf("%d",&a);
                search_index(head,a);
                break;
            case 9:
                printf("enter the nth node which you want to find = ");
                scanf("%d",&a);
                getnode_beg(head,a);
                break;
            case 10:
                printf("enter the nth node from end = ");
                scanf("%d",&a);
                getnode_end(head,a);
                break;
            case 11:
                count(head);
                break;
            case 12:
                middle(head);
                break;
        	case 13:
        		print(head);
        		break;
            case 14:
                head=reverse(head);
                printf("doubly linked list is reversed");
                break;
	    }
	    printf("\n\n");
	}
}


