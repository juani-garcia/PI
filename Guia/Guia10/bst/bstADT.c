#include <stdlib.h>
#include <stdio.h>
#include "bstADT.h"

typedef struct Node * Tree;

typedef struct Node{
    elemType value;
    Tree left;
    Tree right;
} Node;

typedef struct bstCDT{
    Tree root;
    size_t size;
} bstCDT;

bstADT newBst(void){
    return calloc(1, sizeof(bstCDT));
}

void freeRec(Tree node){
    if(node == NULL) return;
    freeRec(node->left);
    freeRec(node->right);
    free(node);
}

void freeBst(bstADT bst){
    freeRec(bst->root);
    free(bst);
}


unsigned int size(const bstADT bst){
    return bst->size;
}

static size_t heightRec(Tree node){
    if(node == NULL) return 0;
    size_t lh = heightRec(node->left) + 1, rh = heightRec(node->right) + 1;
    return lh > rh? lh : rh;
}

unsigned int height(const bstADT bst){
    return heightRec(bst->root);
}

static int belongsRec(Tree node, elemType elem){
    if(node == NULL) return 0;

    int c;
    if((c = compare(elem, node->value)) == 0) return 1;

    if(c < 0) return belongsRec(node->left, elem);
    return belongsRec(node->right, elem);
}

int belongs(const bstADT bst, elemType elem){
    return belongsRec(bst->root, elem);
}

static Tree insertRec(Tree node, elemType elem, int * ok){
    if(node == NULL){
        Tree new = malloc(sizeof(Node));
        new->value = elem;
        new->left = new->right = NULL;
        *ok = 1;
        return new;
    }
    int c = compare(elem, node->value);
    if(c < 0)
        node->left = insertRec(node->left, elem, ok);
    else if(c > 0)
        node->right = insertRec(node->right, elem, ok);
    return node;    

}

int insert(bstADT bst, elemType elem){
    if(bst->root == NULL){
        bst->root = calloc(1, sizeof(Node));
        bst->root->value = elem;
        bst->size++;
        return 1;
    }
    int ok = 0;
    bst->root = insertRec(bst->root, elem, &ok);
    bst->size += ok;
    return ok;
}

static int isBalancedRec(Tree root){
    if (root == NULL)
        return 1;
 
    int diff = heightRec(root->left) - heightRec(root->right);
    diff = diff < 0? -diff : diff;
 
    if (diff <= 1 && isBalancedRec(root->left) && isBalancedRec(root->right))
        return 1;
 
    return 0;
}

int isBalanced(bstADT bst){
    return isBalancedRec(bst->root);
}

void inorderRec(Tree node, elemType * ans, int * dim){
    if(node == NULL) return;
    inorderRec(node->left, ans, dim);
    ans[(*dim)++] = node->value;
    inorderRec(node->right, ans, dim);
}

elemType * inorder(const bstADT bst){
    elemType * ans = malloc(size(bst) * sizeof(elemType));
    int dim = 0;
    inorderRec(bst->root, ans, &dim);
    return ans;
}

