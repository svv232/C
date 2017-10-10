#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* left;
    struct node* right;
    int data;
} ;

struct node* NewNode(int data){
    struct node* nodep = malloc(sizeof(struct node));
    nodep -> left = NULL;
    nodep -> right = NULL;
    nodep -> data = data;
    return nodep;
}

struct node* insert(struct node* nodep,int data){
    if (nodep == NULL){ 
        return NewNode(data);
    }
    else {
        if (data < nodep->data){
            nodep->left = insert(nodep->left,data);
        }
        else{
            nodep->right = insert(nodep->right,data);
        }
    return nodep;
    }
}

struct node*  max(struct node* nod){
    if (nod->right != NULL){
        return max(nod->right);
    }
    return nod;
}

struct node*  build123(){

    struct node* node2 = NewNode(2);

    node2 -> left = NewNode(1);
    node2 -> right = NewNode(3);
    //printf("%d,%d,%d\n",node2->left->data,node2->data,node2->right->data);
    //printf("%d\n",max(node2)->data);

    return node2;
}

int size (struct node* root){
    int left;
    int right;
    if (root == NULL){
        return 0;
    }
    else {
        left = size(root -> left);
        right = size(root->right);
    }
    return 1+left+right;
}


int max_depth(struct node* node){
    return 0;
}

void main(){
   struct node* tree =  build123();
   printf("%d\n",size(tree));
}
