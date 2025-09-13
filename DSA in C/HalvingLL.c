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

void split(struct Node **l1,struct Node **l2, struct Node *head){
    struct Node *fast = head, *slow = head;
    struct Node *temp = head;
    struct Node *midnode;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    midnode = slow;
    while(temp != midnode){
        temp = temp->next;
    }
    temp = temp->next;
    midnode->next = NULL;
    *l1 = head;
    *l2 = temp;

}

void main(){

    struct Node *head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(5);
    head->next->next->next->next->next = new_node(6);



    displayList(head);

    struct Node *l1, *l2;


    split(&l1,&l2,head);

    displayList(l1);
    displayList(l2);





}
