#include"../includes/adtLL.h"
void display(char * string){

    printf("%s \n",string);

}
void displayList(ADT * list){

    printf("List name: %s \n",list->name);

    // creating temp point to iterate throught list
    Node * temp = list->head;
    while(temp !=NULL){
        printf("Node data: %s \n",(char * )temp->data);
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
    free(node->data);
    free(node);
}
ADT * insertNode(ADT* head,void *data){
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

 return head;
}

/// this is bugged , start here;
Node * detachNode(ADT * list, void *data){
    // creating a temp no to detach from list then return it 
    Node * temp = NULL;
    //creating pointer to iterate through list
    Node * head = list->head;
    //finding matching node
    while(!strcmp(data, head->data) || head == NULL){
        head = head->next;
    }

    /// if not equall to null , so their exists a match
    if(head != NULL){
        temp = head;
        // removing  the node
        head = temp->next;
        head->prev = temp->prev;
    }
    

    return  temp;
}