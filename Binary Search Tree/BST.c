
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key; 
    struct Node *left;
    struct Node *right; 
    struct Node *parent; 
}; 

struct Node *createNewNode(int data) { 
    struct Node *newNode =  (struct Node *)malloc(sizeof(struct Node)); 
    newNode->key = data; 
    newNode->left = NULL; 
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode; 
} 

struct Node* search(struct Node* node, int key)  {
    if (node == NULL || node->key == key) 
       return node; 
      
    if (node->key < key) 
       return search(node->right, key); 
  
    return search(node->left, key); 
} 

void printPostorder(struct Node* node) {
     if (node == NULL) 
        return; 
     printPostorder(node->left); 
     printPostorder(node->right); 
     printf("%d ", node->key); 
} 
 
void printInorder(struct Node* node) { 
     if (node == NULL) 
          return; 
  
     
     printInorder(node->left); 
     printf("%d ", node->key);
     printInorder(node->right); 
} 
  
void printPreorder(struct Node* node) { 
     if (node == NULL) 
          return; 
  
     printf("%d ", node->key); 
     printPreorder(node->left);  
     printPreorder(node->right); 
}     
  
struct Node* findMinIterative(struct Node* node) { 
    if(node == NULL) {
        return node;
    }
    while(node->left != NULL) {
        node = node->left;
    }
    return node;
}


struct Node* findMinRecursive(struct Node* node) {
    if(node == NULL) {
        return node;
    }
    if(node->left == NULL) {
        return node;
    }
    return findMinRecursive(node->left);
}

struct Node* findMaxIterative(struct Node* node) { 
    if(node == NULL) {
        return node;
    }
    /* loop down to find the rightmost node */
    while(node->right != NULL) {
        node = node->right;
    }
    return node;
}


struct Node* findMaxRecursive(struct Node* node) { 

    if(node == NULL) {
        return node;
    }
    if(node->right == NULL) {
        return node;
    }    
    return findMaxRecursive(node->right);
}


struct Node* inOrderSuccessor(struct Node *node)  {
    if(node == NULL) {
        return node;
    }
    if( node->right != NULL ) {
        return findMinRecursive(node->right);
    }
    struct Node *p = node->parent; 
    while(p != NULL && node == p->right)  {
        node = p; 
        p = p->parent; 
    } 
    return p; 
} 


struct Node* inOrderSuccessorTopDown(struct Node* root, struct Node* node) {
    if( node->right != NULL )
        return findMinRecursive(node->right);
 
    struct Node *successor = NULL;
 
    while (root != NULL) {
        if (node->key < root->key) {
            successor = root;
            root = root->left;
        }
        else if (node->key > root->key)
            root = root->right;
        else
           break;
    }
    return successor;
}


struct Node* inOrderPredecessor(struct Node* node) {
    if(node == NULL) {
        return node;
    }
    if(node->left != NULL ) {
        return findMaxRecursive(node->left);
    }
    struct Node* p = node->parent;
    while(p !=NULL && node == p->left) {
        node = p;
        p = p->parent;
    }
    return p; 
}

struct Node* inOrderPredecessorTopDown(struct Node* root, struct Node* node) {
    if( node->left != NULL )
        return findMaxRecursive(node->left);
  
    struct Node *predecessor = NULL;
  
    while (root != NULL) {
        if (node->key > root->key) {
            predecessor = root;
            root = root->right;
        }
        else if (node->key < root->key)
            root = root->left;
        else
           break;
    }
    return predecessor;
}

struct Node* insertWithParent(struct Node* node, int key) 
{ 
    if (node == NULL) {
        return createNewNode(key); 
    }
    if (key < node->key) {
        struct Node *lchild = insertWithParent(node->left, key); 
        node->left = lchild; 
        lchild->parent = node; 
    }
    else if (key > node->key) {
        struct Node *rchild = insertWithParent(node->right, key); 
        node->right = rchild; 
        rchild->parent = node; 
    }
  
    return node; 
} 

struct Node* deleteWithParent(struct Node* node, int key) {
    // base case 
    if (node == NULL) {
        return node;
    }
  
    if (key < node->key) {
        node->left = deleteWithParent(node->left, key); 
    }
  
    else if (key > node->key) {
        node->right = deleteWithParent(node->right, key); 
    }
    else { 
        if (node->left == NULL)  {
            struct Node *temp = node->right; 
            free(node); 
            return temp; 
        } 
        else if (node->right == NULL) {
            struct Node *temp = node->left; 
            free(node); 
            return temp; 
        } 
        struct Node* temp = findMinRecursive(node->right); 
  
        node->key = temp->key; 
        node->right = deleteWithParent(node->right, temp->key); 
    } 
    return node; 
} 

struct Node* insert(struct Node* node, int key) 
{ 
    if (node == NULL) {
        return createNewNode(key); 
    }
  
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node; 
} 

struct Node* delete(struct Node* node, int key) {
    if (node == NULL) {
        return node;
    }
    if (key < node->key) {
        node->left = delete(node->left, key); 
    }
    else if (key > node->key) {
        node->right = delete(node->right, key); 
    }
    else { 
        if (node->left == NULL)  {
            struct Node *temp = node->right; 
            free(node); 
            return temp; 
        } 
        else if (node->right == NULL) {
            struct Node *temp = node->left; 
            free(node); 
            return temp; 
        } 
        struct Node* temp = findMinRecursive(node->right); 
        node->key = temp->key; 
        node->right = delete(node->right, temp->key); 
    } 
    return node; 
} 

int main(int argc, char** argv) {
    struct Node *root = NULL; 

    root = insertWithParent(root, 50); 
    root = insertWithParent(root, 30); 
    root = insertWithParent(root, 20); 
    root = insertWithParent(root, 40); 
    root = insertWithParent(root, 70); 
    root = insertWithParent(root, 60); 
    root = insertWithParent(root, 80);

    
    struct Node *node;
    node = findMinRecursive(root);
    if(node == NULL) {
        printf("There is no minimum element as the tree is NULL!\n");
    } else {
        printf("The minimum element is: %d\n", node->key);
    }
    
    
    // print inoder traversal of the BST 
    printf("\nInorder traversal of BST is as follows....\n");
    printInorder(root); 
    printf("\nPreorder traversal of BST is as follows....\n");
    printPreorder(root); 
    printf("\nPostorder traversal of BST is as follows....\n");
    printPostorder(root); 
    
    
    
    /* SEARCH PROCEDURE */
    int element;
    printf("\nEnter the element which you want to search: ");
    scanf("%d",&element);  
    node = search(root, element); 
    if(node == NULL) {
        printf("The element is not present!\n");
    } else {
        printf("The element is present!\n");
    }
    
    
    /* FIND MINIMUM */
    node = findMinIterative(root);
    if(node == NULL) {
        printf("There is no minimum element as the tree is NULL!\n");
    } else {
        printf("The minimum element is: %d\n", node->key);
    }
    
    node = findMinRecursive(root);
    if(node == NULL) {
        printf("There is no minimum element as the tree is NULL!\n");
    } else {
        printf("The minimum element is: %d\n", node->key);
    }
    
    /* FIND MAXIMUM */
    node = findMaxIterative(root);
    if(node == NULL) {
        printf("There is no maximum element as the tree is NULL!\n");
    } else {
        printf("The maximum element is: %d\n", node->key);
    }
    
    node = findMaxRecursive(root);
    if(node == NULL) {
        printf("There is no maximum element as the tree is NULL!\n");
    } else {
        printf("The maximum element is: %d\n", node->key);
    }
    
    
    
    printf("\nEnter the element whose inorder successor you want to find: ");
    scanf("%d",&element);  
    node = search(root, element); 
    if(node == NULL) {
        printf("The element is not present! So Inorder successor is not possible!\n");
    } else {
        struct Node *succ =  inOrderSuccessor(node); 
        if(succ ==  NULL) {
            printf("Inorder successor doesn't exit\n"); 
        } else {
            printf("Inorder successor of %d is %d \n", node->key, succ->key);     
        }
    }
    
    
    printf("\nEnter the element whose inorder predecessor you want to find: ");
    scanf("%d",&element);  
    node = search(root, element); 
    if(node == NULL) {
        printf("The element is not present! So Inorder predecessor is not possible!\n");
    } else {
        struct Node *prec =  inOrderPredecessor(node); 
        if(prec ==  NULL) {
            printf("Inorder predecessor doesn't exit\n"); 
        } else {
            printf("Inorder predecessor of %d is %d \n", node->key, prec->key);     
        }
    }

    return (EXIT_SUCCESS);
}

