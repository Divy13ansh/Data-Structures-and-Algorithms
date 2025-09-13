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

struct Node *alternateNodeMerging(struct Node *l1, struct Node *l2){
    struct Node *temp1 = l1, *t1;
    struct Node *temp2 = l2, *t2;
    struct Node *head = l1;
    while(temp1 || temp2){
        temp1 = temp1->next;
        head->next = temp2;
        head = head->next;
        temp2 = temp2->next;
        head->next = temp1;
        head = head->next;
    }
    return l1;
}

void main(){
    struct Node *l1 = new_node(1);
    l1->next = new_node(3);
    l1->next->next = new_node(5);

    struct Node *l2 = new_node(2);
    l2->next = new_node(4);
    l2->next->next = new_node(6);

    displayList(l1);
    displayList(l2);

    struct Node *head;
    head = alternateNodeMerging(l1, l2);
    displayList(head);
}
