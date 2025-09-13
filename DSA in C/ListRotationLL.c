#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *new_node(int data){
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void displayList(struct Node *head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* rotate_list(struct Node *head, int n){
    struct Node *temp = head;
    struct Node *temp2;
    int c = 0;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }

    int pos = c-n;
    //printf("%d",pos);
    temp = head;
    int i = 0;

    while(i < c-n%c){
        i++;
        //printf("%d",i);
        temp = temp->next;
    }

    //printf("%d",temp->data);
    temp2 = temp->next;
    temp->next = NULL;
    temp = temp2;

    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    //printf("%d",temp2->data);
    temp2->next = head;

    return temp;

}

void main(){
    struct Node *list1 = new_node(1);
    list1->next = new_node(2);
    list1->next->next = new_node(3);
    list1->next->next->next = new_node(4);
    list1->next->next->next->next = new_node(5);
    list1->next->next->next->next->next = new_node(6);
    displayList(list1);

    struct Node *res = rotate_list(list1, 9);
    displayList(res);

}
