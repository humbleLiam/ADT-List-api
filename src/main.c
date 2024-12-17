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
    Node * dNode =  detachNode(list, "Humble");

    displayList(list);


    

    // cleaning memory
    freeList(list);
    return 0;
}