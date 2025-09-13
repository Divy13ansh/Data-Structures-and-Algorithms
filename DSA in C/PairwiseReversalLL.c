#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *new_node(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void displayList(struct Node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *reverse_pairs(struct Node *head){

    if(head == NULL || head->next == NULL){
        return(head);
    }

    struct Node *temp = head;
    struct Node *prev;

    head = head->next;
    temp->next = head->next;
    head->next = temp;

    prev = temp;
    temp = temp->next;

    while(temp != NULL && temp->next != NULL ){
        prev->next = temp->next;
        temp->next = temp->next->next;
        prev->next->next = temp;
        prev = temp;
        temp = temp->next;
    }
    return(head);
}


void main(){
    struct Node *head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(5);
    head->next->next->next->next->next = new_node(6);


    displayList(head);

    head = reverse_pairs(head);

    displayList(head);

}

