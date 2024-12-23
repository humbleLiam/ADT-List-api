#include "../includes/adtLL.h"
int main(int argc , char * argv[]){
    //wrapped print f for fun idk why
    display("my name jeff \n");

    ADT * list = createList("Hello world, List");
    insertNode(list, "Liam");
    insertNode(list, "Humble");
    insertNode(list, "jeff");

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
    return 0;
}  