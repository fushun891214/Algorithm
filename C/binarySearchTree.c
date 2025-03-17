#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree{
    int data;
    int leftsize;
    struct BinarySearchTree *lChild;
    struct BinarySearchTree *rChild;
}BST;

BST *newNode(int x){
    BST *t = (BST *)malloc(sizeof(BST));
    t->data = x;
    t->leftsize = 1;
    t->lChild = NULL;
    t->rChild = NULL;
    return t;
}

BST *insert(BST *t,int x){
    if(t == NULL){
        t = newNode(x);
    }
    else if(t->data < x){
        t->rChild = insert(t->rChild,x);
    }
    else if(t->data > x){
        t->leftsize += 1;
        t->lChild = insert(t->lChild,x);
    }
    return t;
}

BST *searchRecursive(BST *t,int x){
    if(t == NULL){
        return NULL;
    }
    else if(t->data < x){
        return searchRecursive(t->rChild,x);
    }
    else if(t->data > x){
        return searchRecursive(t->lChild,x);
    }
    return t;
}

BST *searchIterative(BST *t,int x){
    int found = 0;
    while(t != NULL && !found){
        if(x < t->data){
            t = t->lChild;
        }
        else if(x > t->data){
            t = t->rChild;
        }
        else if(t->data == x){
            found = 1;
        }
    }
    if(!found){
        return NULL;
    }
    return t;
}

BST *searchK(BST *t,int k){
    int found = 0;
    while(t != NULL && !found){
        if(t->leftsize == k){
            found = 1;
        }
        else if(t->leftsize > k){
            t = t->lChild;
        }
        else{
            k -= t->leftsize;
            t = t->rChild;
        }
    }
    if(!found){
        return NULL;
    }
    return t;
}

void inorderTraversal(BST *t){
    if(t == NULL){
        return;
    }
    inorderTraversal(t->lChild);
    printf("t of data:%d t of leftsize:%d \n",t->data,t->leftsize);
    inorderTraversal(t->rChild);
}

void freeTree(BST *t){
    if(t == NULL){
        return;
    }
    freeTree(t->lChild);
    freeTree(t->rChild);
    free(t);
}

int main(void){
    BST *t = NULL;
    t = insert(t,13);
    t = insert(t,11);
    t = insert(t,19);
    t = insert(t,1);
    t = insert(t,2);
    inorderTraversal(t);
    if(searchRecursive(t,10) != NULL){
        printf("%s","Have found \n");
    }
    if(searchIterative(t,19) != NULL){
        printf("%s","Have found \n");
    }
    if(searchK(t,3) != NULL){
        printf("kth-smallest:%d \n",searchK(t,2)->data);
    }
    freeTree(t);
}