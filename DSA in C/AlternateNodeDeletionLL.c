#include<stdio.h>

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

struct Node *alternateNodeDeletion(struct Node *head){
    struct Node *temp = head;
    while(temp && temp->next){
        struct Node *x;
        x = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        free(x);
        //displayList(head);
    }
    return head;
}

void main(){
    struct Node *l1 = new_node(1);
    l1->next = new_node(2);
    l1->next->next = new_node(3);
    l1->next->next->next = new_node(4);
    l1->next->next->next->next = new_node(5);
    l1->next->next->next->next->next = new_node(6);
    l1->next->next->next->next->next->next = new_node(7);

    displayList(l1);

    l1 = alternateNodeDeletion(l1);

    displayList(l1);
}
