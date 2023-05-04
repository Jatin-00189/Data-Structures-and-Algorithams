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

struct Node* InsertAtIndex(struct Node* head,int index,int data) {

    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    int i = 0;

    while (i!=index-1) {
        p = p->next;
        i++;
    }
    new->next = p->next;
    p->next = new;

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
    head = insteratbegin(head,400);
    printLinkedList(head);

    head=insterAtend(head,500);

    printLinkedList(head);

    head = insterAfterNode(head,second,5000);

    printLinkedList(head);

    //head = InsertAtIndex(head,2,100000);

    printLinkedList(head);

}
