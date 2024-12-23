//header guards
#ifndef SQUARE_H
#define SQUARE_H
// includes 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//data struct
typedef struct node{
    void * data;
    struct node * next;
    struct  node * prev;
}Node;  


typedef struct ADT{
    Node * head;
    Node * tail;
    char * name;
}ADT;

void display(char * );
void displayNode(char *);
ADT * createList(char*);
void freeList(ADT * );
void displayList(ADT *);
Node * createNode(void *);
void freeNode(Node *);
Node * insertNode(ADT * , void *); // return null if the node faild to be created.
Node * searchDetachNode(ADT * , void * );
Node * popNode(ADT * list );
void deleteNPopNode(ADT * list);


// end of hearder guard
#endif