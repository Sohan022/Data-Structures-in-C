              //geeksforgeeks
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int i;
	struct node *left;
	struct node *right;
}node;

int search(int in[],int low,int high, int a)
{
	int j;
	for(j=low;j<high;j++){
	if(in[j]==a)
	return j;
    }
	
}
node *construct_pre(int pre[],int in[],int low,int high)
{
	static int index=0;
	if(low>high)
	return '\0';
	node *temp=(node *)malloc(sizeof(node));
	temp->left='\0';
	temp->right='\0';
	temp->i=pre[index++];
	node *root=temp;
	if(low==high)
	return root;
	int j;
    j=search(in,low,high,root->i);
	root->left=construct_pre(pre,in,low,j-1);
	root->right=construct_pre(pre,in,j+1,high);
	return root;
}

node *construct_post(int post[],int in[],int low,int high,int *n)
{
	if(low>high)
	return '\0';
	node *temp=(node *)malloc(sizeof(node));
	temp->left='\0';
	temp->right='\0';
	temp->i=post[*n];
	(*n)--;
	node *root=temp;
	if(low==high)
	return root;
	int j;
    j=search(in,low,high,root->i);
	root->right=construct_post(post,in,j+1,high,n);
	root->left=construct_post(post,in,low,j-1,n);
	return root;
}
node* buildTree(int in[], int post[], int n) 
{ 
    int pIndex = n - 1; 
    return construct_post(post,in, 0, n - 1, &pIndex); 
} 
void inorder(node *root)
{
	if(root=='\0')
	return;
	inorder(root->left);
	printf("%d  ",root->i);
    inorder(root->right);
}

int main()
{
	node *root='\0';
	int in[100],pre[100],post[100],n,m;
	printf("enter the no. of elements = ");
	scanf("%d",&n);
	printf("1.tree form preorder and inorder\n2.tree from postorder and inorder\n");
	scanf("%d",&m);
	int j;
	switch(m)
	{
		case 1:
			printf("enter the elements in preorder\n");
			for(j=0;j<n;j++)
			scanf("%d",&pre[j]);
			printf("enter the elements in inorder\n");
			for(j=0;j<n;j++)
			scanf("%d",&in[j]);
			root=construct_pre(pre,in,0,n-1);
			printf("output in inorder\n");
			inorder(root);
			break;
		case 2:
			printf("enter the elements in postorder\n");
			for(j=0;j<n;j++)
			scanf("%d",&post[j]);
			printf("enter the elements in inorder\n");
			for(j=0;j<n;j++)
			scanf("%d",&in[j]);
			root=buildTree(in,post,n);
			printf("output in inorder\n");
			inorder(root);
			break;
	}
	return 0;
}
