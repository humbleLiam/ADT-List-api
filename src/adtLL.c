#include"../includes/adtLL.h"
void display(char * string){

    printf("%s \n",string);

}

void displayCard(void * cur){
    Card * pointer = (Card * ) cur;
    printf("Suit: %s Card: %d \n",pointer->suit, pointer->value);    
}

void displayNode(void* nodeDisplay ){
    char * str = (char *) nodeDisplay;
    printf("Node data: %s \n",str);    
}

void displayList(ADT * list){
    printf("List name: %s \n",list->name);
    // creating temp point to iterate throught list
    Node * temp = list->head;
    while(temp !=NULL){
        (*list->display)(temp->data);   
        // updating node to next 
        temp = temp->next;
    }
}
ADT * createList(char* name, void (*display)(void *) ){
    ADT * list = NULL;
    char * temp= NULL;

    // giving the list an name +1 null char
    temp =(char *) malloc(sizeof(char)+strlen(name)+1);
    if(temp == NULL){
        return NULL;
    }
    //copying string to temp
    strcpy(temp,name);

    //creating adt list and checking if malloc works
    list = (ADT*) malloc(sizeof(ADT));
    if(list == NULL){
        return NULL;
    }
    //filling variables into the strutc
    list->head = NULL;
    list->tail = NULL;
    list->name = temp;
    list->display = display;

    return list;
}
void freeList(ADT * list){
    if(list == NULL) return;
    
    // creating temp to iterate through list
    Node * temp = list->head;
    Node * temp2 = temp;
    // freeing nodes first 
    while(temp != NULL){
        temp2 = temp2->next;
        freeNode(temp);
        //setting the temp variable to the pointer to next;
        temp = temp2;
    }

    free(list->name);   
    free(list);
}
Node * createNode(void * data, size_t size){
    // creating node;
    Node * temp = NULL;
    //coping data to temp;
    // creating node
    temp = (Node * ) malloc(sizeof(Node));
    //check for null hehe
    if(temp == NULL){
        return NULL;
    }
    
    temp->data = malloc(size);
        //check for null hehe
    if(temp == NULL){
        return NULL;
    }
    memcpy(temp->data, data, size);

    //assing pointers to node
    temp->next = NULL;
    temp->prev = NULL;
    return temp ;
}
Card * createCard(char * suit, int value){
    Card *card =(Card *) malloc(sizeof( Card));

     if (card == NULL) {
        fprintf(stderr, "Memory allocation failed for Card\n");
        return NULL;
    }

    strncpy(card->suit, suit, sizeof(card->suit) - 1);
    card->suit[sizeof(card->suit) - 1] = '\0';
    card->value = value;

    return card;
}


void freeNode(Node * node){
    if(node !=NULL){ /* To make sure i am not free null goes bye bye*/
        free(node->data);
        free(node);
    }
}


//need to update to fix !!!!!!!!!!!!!!!!!!!!!11
Node * insertNode(ADT* head,void *data, size_t size){
    // create the node
    Node * temp = createNode(data, size);
    // check null
    if(temp == NULL){
        fprintf(stdout,"ERRROR-FAILED_TO_CREATE_NODE\n");
        return NULL;
    }

    //assing head values
    temp->next = head->head;
    temp->prev = NULL;
    head->head = temp;

    return temp;
}
Node * searchDetachNode(ADT * list, void *data){
    // creating a temp no to detach from list then return it 
    // prev is the node before head andb it only removes if found 
    Node * temp = NULL, * prev = NULL;
    //creating pointer to iterate through list
    Node * head = list->head;
    //finding matching node
    while(head != NULL && strcmp(data, head->data) ){
        prev = head;
        head = head->next;
    }
    /// if not equall to null , so their exists a match
    if(head != NULL){
        displayNode((char * )head->data);
        // removing  the node
        //assigning the previous node of head variable and assing the it the index node next
        //skipping it 
        if(prev != NULL ){
            prev->next = head->next;    
        } else {
            list->head = head->next;
        }

        temp = head;
    } 

    return temp;        
}   
Node * popNode(ADT * list ){
    Node * temp = NULL;
    temp = list->head;
    list->head = temp->next;

    return temp;
}

void  deleteNPopNode(ADT * list ){

    Node * temp = popNode(list);
    freeNode(temp);

}

char * findStringSuit(int number){
    static char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    return suits[number % 4];

}