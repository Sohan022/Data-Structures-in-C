#include <stdio.h> 
#include<stdlib.h>
  

typedef struct Node 
{ 
    int key; 
    struct Node* left, *right; 
}Node; 
  

int search(int arr[], int strt, int end, int value) 
{ 
int i;
    for ( i = strt; i <= end; i++) 
        if (arr[i] == value) 
            return i; 
    return -1; 
} 
  
int *extrackKeys(int in[], int level[], int m, int n) 
{ 
    int *newlevel =  in[m], j = 0,i; 
    for ( i = 0; i < n; i++) 
        if (search(in, 0, m-1, level[i]) != -1) 
            newlevel[j] = level[i], j++; 
    return newlevel; 
} 
  

Node* newNode(int key) 
{ 
    Node *node = (Node *)malloc(sizeof(Node));
	 
    node->key = key; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
Node* buildTree(int in[], int level[], int inStrt, int inEnd, int n) 
{ 
  
  
    if (inStrt > inEnd) 
        return NULL; 
  
  
    Node *root = newNode(level[0]); 
  
  
    if (inStrt == inEnd) 
        return root; 
  
  
    int inIndex = search(in, inStrt, inEnd, root->key); 
  
  
    int *llevel  = extrackKeys(in, level, inIndex, n); 
  
  
    int *rlevel  = extrackKeys(in + inIndex + 1, level, n-inIndex-1, n); 
  
  
    root->left = buildTree(in, llevel, inStrt, inIndex-1, n); 
    root->right = buildTree(in, rlevel, inIndex+1, inEnd, n); 
  
  
    free(llevel); 
    free(rlevel); 
  
    return root; 
} 
  
void printInorder(Node* node) 
{ 
    if (node == NULL) 
       return; 
    printInorder(node->left); 
    printf("%d  ",node->key); 
    printInorder(node->right); 
} 
  

int main() 
{ 
    int in[]    = {4, 8, 10, 12, 14, 20, 22}; 
    int level[] = {20, 8, 22, 4, 12, 10, 14}; 
    int n = sizeof(in)/sizeof(in[0]); 
    Node *root = buildTree(in, level, 0, n - 1, n); 
  
 
 
    printInorder(root); 
  
    return 0; 
}
