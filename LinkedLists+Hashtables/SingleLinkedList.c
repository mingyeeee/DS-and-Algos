/* Mingye Chen 2020-09-09
 * Node->next need to be null if it is last element
 * list element index starts at 1 not 0
 * Functions: insertFront, insertAfter, insertLast, deleteNode, deleteList, printList
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void insertFront(Node** headref, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *(headref);
    *(headref) = newNode;
}

//index starts at 0 so position starts at 1
void insertAfter(Node* head, unsigned int position, int data){
    if(position == 0||head == NULL){
        printf("position cannot be 0");
    } 
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    //position -1 to end up on the position which you want to insert node after
    for(unsigned int i = 0; i<position-1; i++){
        head = head->next;
    }
    newNode->next = head->next;
    head->next = newNode;
}

void insertLast(Node* head, int data){
    while(head->next != NULL){
        head = head->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    head->next = newNode;
}
//index starts at 0 so position starts at 1
void deleteNode(Node** head, int position){
    // If linked list is empty 
    if (*head == NULL) 
        return; 
    
    Node* temp = *head;
    // If head needs to be removed 
    if (position == 1) 
    { 
        *head = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<position-2; i++) {
         temp = temp->next; 
  
        // If position is more than number of nodes 
        if (temp == NULL || temp->next == NULL){ 
            return;
        }
    }

    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    Node *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list 
}
void deleteList(Node* head){
    Node* nextToDelete;
    do{
        nextToDelete = head->next;
        printf("deleting %d \n", head->data);
        free(head);
        head = nextToDelete;
    }while(head != NULL);
    printf("finished deleting list\n");
}

void printList(Node* head){
    do{
        printf("%d \n", head->data);
        head = head->next;
    }while(head != NULL);
    printf("\n");
}

int main(){
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = 3;
    node1->next = NULL;
    Node* headref = node1;

    insertFront(&headref, 1);
    //add after node in position 1
    insertAfter(headref, 1, 2);
    insertLast(headref, 4);
    printList(headref);

    deleteNode(&headref, 4);
    printList(headref);

    deleteNode(&headref, 2);
    printList(headref);

    deleteNode(&headref, 1);
    printList(headref);

    deleteList(headref);

    return 0;
}
