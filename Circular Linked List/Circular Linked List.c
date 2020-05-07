#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int i;
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
    do
    {
        printf("%d  ",t->i);
        t=t->next;
    }
    while(t!=head);
}
node *insert_beg(node *head,int a)
{
    node *t=(node *)malloc(sizeof(node));
    t->i=a;
    node *p=head;
    if(head=='\0')
    {
       head=t;
       t->next=head;
       return head;
    }
    t->next=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    head=t;
    p->next=head;
    return head;
}
node *insert_end(node *head,int a)
{
    node *p,*t=(node *)malloc(sizeof(node));
    t->i=a;
    p=head;
    if(head=='\0')
    {
       head=t;
       t->next=head;
       return head;
    }
    do
    {
        p=p->next;
    }
    while(p->next!=head);
    p->next=t;
    t->next=head;
    return head;
}
node *insert_index(node *head,int a,int j)
{
    node *p,*t=(node *)malloc(sizeof(node));
    t->i=a;
    int c=1;
    p=head;
    if(j==1&&head=='\0')
    {
       head=t;
       t->next=head;
       return head;
    }
    if(j==1)
    {
         do
         {
           p=p->next;
         }
         while(p->next!=head);
         t->next=head;
         head=t;
         p->next=head;
         return head;
    }
    while(c!=j-1)
    {
        ++c;
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
    return head;
}
node *delete_key(node *head,int a)
{
    node *t,*p;
	int c=0;
	t=head;
	while(t->i!=a)
	{
		p=t;
		t=t->next;
		c++;
	}
	if(c==0&&head->next==head)
    {
        free(head);
        head='\0';
        return head;
    }
	if(c==0)
	{
		p=head;
		do
         {
           p=p->next;
         }
         while(p->next!=head);
         head=head->next;
         p->next=head;
	}
	else
	{
    	p->next=t->next;
	}
	t->next='\0';
	free(t);
	return head;
}
node *delete_index(node *head,int a)
{
    node *t,*p;
	int c=1;
	t=head;
	while(c!=a)
	{
		p=t;
		t=t->next;
		c++;
	}
	if(c==1&&head->next==head)
    {
        free(head);
        head='\0';
        return head;
    }
	if(c==1)
	{
		p=head;
		do
         {
           p=p->next;
         }
         while(p->next!=head);
         head=head->next;
         p->next=head;
	}
	if(c==1)
	{
		head=head->next;
	}
	else
	{
		p->next=t->next;
	}
	t->next='\0';
	free(t);
	return head;
}
void search_key(node *head,int a)
{
    node *t=head;
    do
    {
        if(t->i==a)
        {
            printf("%d is found",a);
            return;
        }
        t=t->next;
    }
    while(t!=head);
    if(t==head)
    {
        printf("%d is not found",a);
    }
}
node *delete_ll(node *head)
{
    node *t,*p;
    while(1)
    {
        t=head;
        p=head;
        if(head->next==head)
        {
            free(t);
            head='\0';
            printf("entire linked list has deleted");
            return head;
        }
		do
        {
           p=p->next;
        }
        while(p->next!=head);
        head=head->next;
        p->next=head;
        t->next='\0';
        free(t);
    }
}
void *search_index(node *head,int a)
{
    node *t=head;
    int c=1;
    while(c!=a)
    {
        t=t->next;
        if(t==head)
        {
            break;
        }
        c++;
    }
    if(c==a)
    {
        printf("element %d is found at index %d",t->i,a);
    }
    else
    {
        printf("index %d is not found",a);
    }
}
void getnode_beg(node *head,int a)
{
    node *t=head;
    int c=1;
    while(c!=a)
    {
        t=t->next;
        if(t==head)
        {
            break;
        }
        c++;
    }
    if(c==a)
    {
        printf("element %d is found at node %d",t->i,a);
    }
    else
    {
        printf("index %d is not found",a);
    }
}
void getnode_end(node *head,int a)
{
    int d,c=0,e=1;
    node *t=head;
    while(1)
    {
        t=t->next;
        c++;
        if(t==head)
        {
            break;
        }
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
    while(1)
    {
        t=t->next;
        c++;
        if(t==head)
        {
            break;
        }
    }
    printf("%d node in linked list",c);
}
void middle(node *head)
{
    int c=0,d,e=1;
    node *t=head;
    while(1)
    {
        t=t->next;
        c++;
        if(t==head)
        {
            break;
        }
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
    node *t,*p='\0';
    t=head;
    node *s=head;
    while(1)
    {
        t=t->next;
        s->next=p;
        p=s;
        s=t;
        if(t==head)
        {
            break;
        }
    }
    head->next=p;
    head=p;
    printf("your linked list is reversed");
    return head;
}
int main()
{
	node *head='\0';
	int j,a,m;
	menu();
	while(1)
	{
    	printf("press -1 to 14 for operation in linked list\n");
		scanf("%d",&m);
		if(m==-1)
		{
			break;
		}
		switch(m)
		{
			case 0:
				menu();
				break;
			case 1:
				printf("enter the element which is insert in list = ");
				scanf("%d",&a);
				head=insert_beg(head,a);
				printf("inserted");
				break;
			case 2:
				printf("enter the element which is insert in list = ");
				scanf("%d",&a);
				head=insert_end(head,a);
				printf("inserted");
				break;
			case 3:
				printf("enter the index position where list is inserted = ");
				scanf("%d",&j);
				printf("enter the element which is insert in list = ");
				scanf("%d",&a);
				head=insert_index(head,a,j);
				printf("inserted");
				break;
			case 4:
				printf("enter the key which you want to delete in list = ");
				scanf("%d",&a);
				head=delete_key(head,a);
				printf("deleted");
				break;
			case 5:
				printf("enter the index of list which you want to delete = ");
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
                break;
		}
		printf("\n\n");
	}
	return 0;
}
