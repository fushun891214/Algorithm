#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree{
    int data;
    int leftSize;
    struct BinarySearchTree *LChild;
    struct BinarySearchTree *RChild;
}BST;

BST *newNode(int x){
    BST *t = (BST *)malloc(sizeof(BST));
    t->data = x;
    t->leftSize = 1;
    t->LChild = NULL;
    t->RChild = NULL;
    return t;
}

BST *insertRecursive(BST *t,int x){
    if(t == NULL){
        return newNode(x);
    }
    else if(x > t->data){
        t->RChild = insertRecursive(t->RChild,x);
    }
    else if(x < t->data){
        t->leftSize += 1;
        t->LChild = insertRecursive(t->LChild,x);
    }
    return t;
}

BST *insertInterative(BST *t,int x){
    int found = 0;
    BST *p = t;
    BST *q = p;
    while(p != NULL && !found){
        q = p;
        if(x == p->data){
            found = 1;
        }
        else if(x > p->data){
            p = p->RChild;
        }
        else{
            p = p->LChild;
        }
    }
    if(!found){
        p = (BST *)malloc(sizeof(BST));
        p->data = x;
        p->LChild = NULL;
        p->RChild = NULL;
        p->leftSize = 1;
        if(t){
            if(x > q->data){
                q->RChild = p;
            }
            else{
                q->LChild = p;
            }
        }
        else{
            t = p;
        }
    }
    return t;
}

BST *searchRecursive(BST *t,int x){
    if(t == NULL){
        printf("%s","Not found!\n");
        return NULL;
    }
    else if(x == t->data){
        printf("Found %d!\n",t->data);
        return t;
    }
    else if(x < t->data){
        return searchRecursive(t->LChild,x);
    }
    return searchRecursive(t->RChild,x);
}

BST *searchIterative(BST *t,int x){
    int found = 0;
    while(t != NULL && !found){
        if(t->data == x){
            printf("Found %d!\n",t->data);
            found = 1;
        }
        else if(x > t->data){
            t = t->RChild;
        }
        else{
            t = t->LChild;
        }
    }
    if(!found){
        printf("%s","Not found!\n");
        return NULL;
    }
    return t;
}

BST *searchK(BST *t,int k){
    int found = 0;
    while(t != NULL && !found){
        if(k == t->leftSize){
            found = 1;
        }
        else if(k < t->leftSize){
            t = t->LChild;
        }
        else if(k > t->leftSize){
            k -= t->leftSize;
            t = t->RChild;
        }
    }
    if(!found){
        printf("%s\n","Not found!");
        return NULL;
    }
    printf("Found k:%d\n",t->data);
    return t;
}

void freeBST(BST *t){
    if(t == NULL){
        return;
    }
    freeBST(t->LChild);
    free(t);
    freeBST(t->RChild);
}

void inorderTraversal(BST *t){
    if(t == NULL){
        return;
    }
    inorderTraversal(t->LChild);
    printf("%d \n",t->data);
    inorderTraversal(t->RChild);
}

int main(void){
    BST *t = NULL;
    t = insertInterative(t,110);
    t = insertRecursive(t,10);
    t = insertRecursive(t,5);
    t = insertRecursive(t,21);
    t = insertRecursive(t,2);
    t = insertRecursive(t,99);
    insertInterative(t,101);
    inorderTraversal(t);
    searchRecursive(t,21);
    searchIterative(t,20);
    searchK(t,3);
    freeBST(t);
}