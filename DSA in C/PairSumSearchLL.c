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
};

void displayList(struct Node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

void pairSum(struct Node *head, int target){
    struct Node *first = head, *second = head;
    int flag = 0;
    while(first != NULL){
        second = first->next;
        while(second != NULL){
              if(first->data + second->data == target){
                printf("%d\t%d\n", first->data, second->data);
                flag = 1;
                //return;
              }
              second = second->next;
        }
        first = first->next;
    }
    if(flag == 0){
        printf("Pair not found");
    }
}

void main(){

    struct Node *head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(5);
    head->next->next->next->next->next = new_node(6);

    displayList(head);

    pairSum(head,5);
}
