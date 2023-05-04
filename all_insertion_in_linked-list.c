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

void main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //allocating Heap Memory (Dynamic Memory)

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // 1st
    head->data = 100;
    head->next = second;

    //2nd
    second->data = 200;
    second->next = third;

    //3rd
    third->data = 300;
    third->next = NULL;


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

}
