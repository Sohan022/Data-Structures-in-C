#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n_col=0;
typedef struct node{
        int data;
        struct node *next;
}node;
int size(node *head)
{
    int l=0;
    node *t=head;
    while(t)
    {
        l++;
        t=t->next;
    }
    return l;
}
node *insert(node *head,int a)
{
    node *new=(node *)malloc(sizeof(node));
    new->data=a;
    if(head=='\0')
    {
        new->next='\0';
        head=new;
        return head;
    }
    else
    {
        n_col++;
        new->next=head;
        head=new;
        return head;
    }
}

int main()
{
    int a[1000],t,j,i,n,m;
    printf("enter the no. of elements = ");
    scanf("%d",&n);
    srand(time(0));
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(i=n-1;i>0;i--)
    {
        j=rand()%(i+1);
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    for(i=0;i<n;i++)
    printf("%d,  ",a[i]);
    printf("\nenter the no. of slot = ");
    scanf("%d",&m);
    int b;
    node *h[m];
    for(i=0;i<m;i++)
    h[i]='\0';
    for(i=0;i<n;i++)
    {
    	b=a[i]%m;
    	h[b]=insert(h[b],a[i]);
	}
	printf("no. of collision %d\n",n_col);
	for(i=0;i<m;i++)
    {
        printf("index %d, size of linked list = %d\n",i,size(h[i]));
    }
    return 0;
}
