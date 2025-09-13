#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* new_node(int data){
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

struct Node *sorted_merge(struct Node *x, struct Node *y){
    struct Node *result = NULL;

    if(!x) return y;
    if(!y) return x;

    if(x->data <= y->data){
        result = x;
        result->next = sorted_merge(x->next, y);
    }
    else{
        result = y;
        result->next = sorted_merge(x,y->next);
    }
    return result;
}

struct Node* getMiddle(struct Node *head){
    if(!head) return head;

    struct Node *slow = head, *fast = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node* mergeSort(struct Node *head){
    if(!head || !head->next) return head;

    struct Node *middle = getMiddle(head);
    struct Node *nextOfMiddle = middle->next;
    middle->next = NULL;

    struct Node *left = mergeSort(head);
    struct Node *right = mergeSort(nextOfMiddle);

    struct Node *sortedList = sorted_merge(left,right);
    return sortedList;
}

void main(){
    struct Node *list = new_node(1);
    list->next = new_node(7);
    list->next->next = new_node(2);
    list->next->next->next = new_node(4);

    displayList(list);
    struct Node *result = mergeSort(list);
    displayList(result);
}
