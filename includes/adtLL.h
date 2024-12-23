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
    void (*display)(void * );
    void * (*create)(void * data);
}ADT;


typedef struct card{
    char suit[10];
    int value; 
} Card;

void display(char * );
void displayNode(void *);
void displayCard(void * );
ADT * createList(char*, void(* display)(void *));
void freeList(ADT * );
void displayList(ADT *);
Node * createNode(void * , size_t);
Card * createCard(char * , int);
void freeNode(Node *);
Node * insertNode(ADT * , void *, size_t ); // return null if the node faild to be created.
Node * searchDetachNode(ADT * , void * );
Node * popNode(ADT * list );
void deleteNPopNode(ADT * list);
char * findStringSuit (int number);


// end of hearder guard
#endif