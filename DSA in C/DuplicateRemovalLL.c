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

void removeDuplicates(struct Node *head){
    struct Node *temp = head;
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            struct Node *x = temp->next;
            temp->next = temp->next->next;
            free(x);
        }
        else{
            temp = temp->next;
        }
    }
    return;
}

void main(){
    struct Node *list = new_node(1);
    list->next = new_node(2);
    list->next->next = new_node(2);
    list->next->next->next = new_node(2);
    list->next->next->next->next = new_node(3);

    displayList(list);
    removeDuplicates(list);
    displayList(list);
}
