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

void swap(struct Node *head, int k){
    struct Node *temp = head;
    struct Node *temp2 = head;
    int c = 0;
    while(temp!=NULL){
        c++;
        temp = temp->next;
    }
    int k_from_last = c-k;
    int i = 0;
    temp = head;
    while(i < k-2){
        i++;
        temp = temp->next;
    }
    i = 0;
    while(i < k_from_last-1){
        i++;
        temp2 = temp2->next;
    }
    struct Node *k1, *k2;
    k1 = temp->next;
    temp->next = temp2->next;
    temp2->next = k1;
    k2 = temp->next->next;
    temp->next->next = temp2->next->next;
    temp2->next->next = k2;
}

void main(){
    struct Node *list = new_node(1);
    list->next = new_node(2);
    list->next->next = new_node(3);
    list->next->next->next = new_node(4);
    list->next->next->next->next = new_node(5);
    list->next->next->next->next->next = new_node(6);
    list->next->next->next->next->next->next = new_node(7);
    list->next->next->next->next->next->next->next = new_node(8);

    displayList(list);
    swap(list,2);
    displayList(list);
}
