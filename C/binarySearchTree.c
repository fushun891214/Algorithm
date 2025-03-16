#include <stdlib.h>
#include <stdio.h>

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree *lChild;
    struct BinarySearchTree *rChild;
}BST;

BST *newNode(int x){
    BST *t = (BST *)malloc(sizeof(BST));
    t->data = x;
    t->lChild = NULL;
    t->rChild = NULL;
    return t;
}

BST *insert(BST *t,int x){
    if(t == NULL){
        return newNode(x);
    }
    else if(t->data < x){
        t->rChild = insert(t->rChild,x);
    }
    else if(t->data > x){
        t->lChild = insert(t->lChild,x);
    }
    return t;
}

BST *search(BST *t,int x){
    if(t == NULL){
        return NULL;
    }
    else if(t->data < x){
        return search(t->rChild,x);
    }
    else if(t->data > x){
        return search(t->lChild,x);
    }
    return t;
}

void inorderTraversal(BST *t){
    if(t == NULL){
        return;
    }
    inorderTraversal(t->lChild);
    printf("%d ",t->data);
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
    t = insert(t,5);
    t = insert(t,3);
    t = insert(t,8);
    inorderTraversal(t);
    if(search(t,8) != NULL){
        printf("%s","Turn up");
    }
    freeTree(t);
}