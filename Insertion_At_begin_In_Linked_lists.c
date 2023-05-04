#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head,int data) {
    struct Node* new;
    new = (struct Node*)malloc(sizeof(struct Node));

    if(new == NULL) {
        printf("Overflow");
    }else {
        new->data = data;
        new->next = head;
        head = new;

        return head;
    }


}

void main() {
    struct Node* head;
    head = insert(head,20);
    head = insert(head,30);
    struct Node* temp=head;
    
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
