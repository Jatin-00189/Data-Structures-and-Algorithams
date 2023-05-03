#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printLinkedList(struct Node* n) {
    while(n != NULL) {
        printf(" %d ",n->data);
        n = n->next;
    }
}

void main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //allocating Heap Memory

    head = (struct Node*)malloc(sizeof(struct Node))
    second = (struct Node*)malloc(sizeof(struct Node))
    third = (struct Node*)malloc(sizeof(struct Node))

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




}
