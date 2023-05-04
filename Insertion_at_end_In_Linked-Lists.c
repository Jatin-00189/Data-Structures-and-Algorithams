#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head,int data) {

    struct Node* new_node=NULL;
    new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = NULL;

    if(head==NULL) {
        head = new_node;
    }else {
        struct Node* temp=head;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

int main() {
    struct Node* head=NULL;

    head=insert(head,10);
    head=insert(head,20);
    head=insert(head,30);
    head=insert(head,50);
    head=insert(head,40);


    struct Node* temp=head;

    while(temp!=NULL) {
        printf("%d",temp->data);
        temp=temp->next;
    }


    return (0);


}
