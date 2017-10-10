#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    struct node* next;
    int data;
} node_default = {NULL,NULL,0};

struct list {
    struct node* head;
    struct node* tail;
};

void initialize(struct list* list){
    list -> head = malloc(sizeof(struct node));
    list -> tail = malloc(sizeof(struct node));
    list -> head -> next = list -> tail;
    list -> tail -> prev = list -> head;
}

void append(struct list LL, int data){
    struct node* newnode = malloc(sizeof(struct node));
    newnode -> data = data;
    LL.head -> next -> prev = newnode;
    newnode -> next = LL.head -> next;
    LL.head -> next = newnode;
    newnode -> prev = LL.head;
}

void printDestroy(struct list LL){
    struct node* node = LL.head;
    while (node != LL.tail -> prev) {
        node = node -> next;
        printf("%d\n",node -> data);
        free(node -> prev);
    }
    free(LL.tail);
}

void main() {
    int i;
    struct list LL;
    initialize(&LL);
    for (i=0;i<8;i++){
        append(LL,i);
    }
    printDestroy(LL);
}
