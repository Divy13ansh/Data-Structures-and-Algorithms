#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *new_node(int data){
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->next = NULL;
    node->data = data;
    return node;
};

void displayList(struct Node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *add_lists(struct Node *list1, struct Node *list2){
    struct Node *res = NULL;
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;
    while(list1 != NULL || list2 != NULL){
        sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        temp = new_node(sum);

        if(res == NULL){
            res = temp;
        }
        else{
            prev->next = temp;
        }
        prev = temp;

        if(list1)
            list1 = list1->next;
        if(list2)
            list2 = list2->next;
    }

    if(carry > 0){
        temp->next = new_node(carry);
    }
    return res;
};

void main(){
    struct Node *list1 = new_node(8);
    list1->next = new_node(7);
    list1->next->next = new_node(9);
    list1->next->next->next = new_node(2);

    printf("List 1: \n");
    displayList(list1);

    struct Node *list2 = new_node(2);
    list2->next = new_node(1);
    list2->next->next = new_node(2);
    list2->next->next->next = new_node(3);

    printf("List 2: \n");
    displayList(list2);

    struct Node *result = add_lists(list1,list2);

    printf("\nAdding 2 lists: \n");
    displayList(result);
}
