#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

void append_data(struct Node **head, int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if(*head == NULL){
        *head = node;
    }
    else{
        struct Node *last = *head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = node;
    }
}

void displayList(struct Node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

void interleave(struct Node *l1, struct Node *l2){
    struct Node *head1  = l1;
    struct Node *head2 = l2;
    struct Node *next1 = head1, *next2 = head2;
    while(head1 != NULL && head2 != NULL){
        next1 = head1->next;
        head1->next = head2;
        head1 = next1;

        next2 = head2->next;
        head2->next = head1;
        head2 = next2;
    }
}

void main(){
    struct Node *l1 = NULL;
    append_data(&l1,1);
    append_data(&l1,3);
    append_data(&l1,5);
    displayList(l1);
    struct Node *l2 = NULL;
    append_data(&l2,2);
    append_data(&l2,4);
    append_data(&l2,6);
    displayList(l2);

    interleave(l1,l2);
    displayList(l1);
    displayList(l2);


}
