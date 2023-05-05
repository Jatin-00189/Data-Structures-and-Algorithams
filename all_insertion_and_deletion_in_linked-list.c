#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insteratbegin(struct Node* head,int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));

    if (head==NULL) {
        head = new;
    }else {
        new->data = data;
        new->next = head;
        head = new;
        return head;
    }
}

struct Node* insterAtend(struct Node* head,int data) {

    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    new->data = data;
    new->next=NULL;
     
    while(temp->next!=NULL) {
        temp=temp->next;
    }

    temp->next = new;
    return head;
    
}

struct Node* insterAfterNode(struct Node* head,struct Node* prev_node,int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;

    new->next = prev_node->next;
    prev_node->next = new;

    return head;
}

void printLinkedList(struct Node* n) {
    while(n != NULL) {
        printf(" %d ",n->data);
        n = n->next;
    }
}

struct Node* insertAtIndex(struct Node* head, int index, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (index == 0) {
        new_node->next = head;
        head = new_node;
        return head;
    }

    struct Node* current = head;
    int i = 0;
    while (i < index - 1 && current != NULL) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        printf("Error: index out of range");
        return head;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

//delete at begin

struct Node* deleteAtBegin(struct Node* head) {
    struct Node* ptr = head;

    head = head->next;
    free(ptr);
    return head;
}

// Delete At Index

struct Node* deleteAtIndex(struct Node* head,int index) {
    struct Node* ptr = head;
    struct Node* delet_node = head->next;

    int i;

    for(i = 0; i<index-1 ; i++) {
        ptr = ptr->next;
        delet_node = delet_node->next;
    }

    ptr->next = delet_node->next;
    free(delet_node);
    return head;
}

//delete at end 

struct Node* deleteAtend(struct Node * head) {
    struct Node* ptr = head;
    struct Node* end = head->next;

    while(end->next!=NULL) {
        ptr = ptr->next;
        end = end->next;
    }

    ptr->next = NULL;

    free(end);
    return head;
}

//delete at given value

struct Node* deleteAtvalue(struct Node* head,int value) {
    struct Node* ptr = head;
    struct Node* delete = head->next;

    while(delete->data!=value && delete->next!=NULL) {
        ptr = ptr->next;
        delete = delete->next;

    }

    if (delete->data == value) {
        ptr->next = delete->next;
        free(delete);
    }
    return head;
}
void main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* four = NULL;
    struct Node* five = NULL;

    //allocating Heap Memory (Dynamic Memory)

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    four = (struct Node*)malloc(sizeof(struct Node));
    five = (struct Node*)malloc(sizeof(struct Node));


    // 1st
    head->data = 100;
    head->next = second;

    //2nd
    second->data = 200;
    second->next = third;

    //3rd
    third->data = 300;
    third->next = four;

    //4th

    four->data = 400;
    four->next = five;

    //5th

    five->data = 500;
    five->next = NULL;


    // PrintT The List
    printLinkedList(head);


    //Abhi bhut kam baki jaise ki insertion , Searching , deletion ;((((()))))
    // Inster at beginning :)
    head = insteratbegin(head,400);
    // After insertion at Begin
    printLinkedList(head);
    // Insert at end of the list
    head=insterAtend(head,500);
    // Print After inserting at end
    printLinkedList(head);
    //inserting after a specific node :)
    head = insterAfterNode(head,second,5000);
    //Print inserting after the node
    printLinkedList(head);
    //insterting at specific Index :)
    head = insertAtIndex(head,2,100000);
    //Final Print (After applying insertAtIndex)
    printLinkedList(head); 
    // Delete AT Beginning of the list
    head = deleteAtBegin(head);

    //print the list after deletion

    printLinkedList(head);

    //Delete At index
    printf("After deletion at index");
    // calling function
    head = deleteAtIndex(head,3);
    //print list
    printLinkedList(head);

    //delete At end of the list

    head = deleteAtend(head);
    // print after deletion at end
    printLinkedList(head);

    //deleteion where a given value match

    head = deleteAtvalue(head,400);

    //print after deletion

    printLinkedList(head);
}
