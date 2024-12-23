#include "../includes/adtLL.h"
int main(int argc , char * argv[]){
    //wrapped print f for fun idk why
    display("my name jeff \n");

    ADT * list = createList("Hello world, List", displayNode);
    insertNode(list, "Liam",strlen("Liam")+1);
    insertNode(list, "Humble", strlen("Humble")+1);
    insertNode(list, "jeff", strlen("jeff")+1);

    displayList(list);
    //update list
    Node * dNode =  searchDetachNode(list, "Humble");
    printf("returned\n");
    Node * doeNode =  searchDetachNode(list, "WORD");


    if(doeNode == NULL){
        printf("Doesnt existL\n");
    }

    displayList(list);
    // displayNode(dNode);

    // cleaning memory
    freeNode(doeNode);
    freeNode(dNode);
    freeList(list);

    printf("Cleaned\n"); 
    //creating a 52 card deck from the linked list
    ADT * deck = createList("52 card deck linked-list repersentation", displayCard);
    printf("deck made\n");

    for(int i = 1; i<14; i++){
        for(int k = 0; k<4; k++){
            Card * card = createCard(findStringSuit(k),i);
            displayCard(card);
            insertNode(deck,card, sizeof(Card));
        }

    }
    // displayList(deck);

    freeList(deck);

    return 0;
}  