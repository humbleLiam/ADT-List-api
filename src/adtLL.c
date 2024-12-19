#include"../includes/adtLL.h"
void display(char * string){

    printf("%s \n",string);

}
void displayNode(char * nodeDisplay ){
    printf("Node data: %s \n",nodeDisplay);    
}
void displayList(ADT * list){
    printf("List name: %s \n",list->name);
    // creating temp point to iterate throught list
    Node * temp = list->head;
    while(temp !=NULL){
        displayNode((char * )temp->data);    
        // updating node to next 
        temp = temp->next;
    }
}
ADT * createList(char* name){
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

    return list;
}
void freeList(ADT * list){
    
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
Node * createNode(void * data){
    // creating node;
    Node * temp = NULL;
    char * string = NULL;
    // assing data is some string however long.
    string = (char * ) malloc(sizeof(char) + strlen(data)+1);
    //check if null
    if(string == NULL){
        return NULL;
    }
    //coping data to temp;
    strcpy(string,data);
   
    // creating node
    temp = (Node * ) malloc(sizeof(Node));
    //check for null hehe
    if(temp == NULL){
        return NULL;
    }

    //assing pointers to node
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = string;

    return temp ;
}
void freeNode(Node * node){
    if(node !=NULL){ /* To make sure i am not free null goes bye bye*/
        free(node->data);
        free(node);
    }
}
void * insertNode(ADT* head,void *data){
    // create the node
    Node * temp = createNode(data);
    // check null
    if(temp == NULL){
        fprintf(stdout,"ERRROR-FAILED_TO_CREATE_NODE\n");
        return NULL;
    }

    //assing head values
    temp->next = head->head;
    temp->prev = NULL;
    head->head = temp;
}


Node * detachNode(ADT * list, void *data){
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
