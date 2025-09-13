#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* new_node(int data){
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node * partition_List(struct Node *head, int x){
    struct Node *before_start = NULL;
    struct Node *before_end = NULL;
    struct Node *after_start = NULL;
    struct Node *after_end = NULL;
    struct Node *current = head;

    while(current){
        if(current->data < x){
            if(!before_start){
                before_start = current;
                before_end = before_start;
            }
            else{
                before_end->next = current;
                before_end = current;
            }
        }
        else{
            if(!after_start){
                after_start = current;
                after_end = current;
            }
            else{
                after_end->next = current;
                after_end = current;
            }
        }
        current = current->next;
    }
    if(before_start){
        before_end->next = after_start;
        after_end->next = NULL;
        return before_start;
    }
    else{
        return after_start;
    }

}

void displayList(struct Node *h){
    struct Node *temp = h;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

void main(){
    int n;

    struct Node *list = new_node(3);
    list->next = new_node(5);
    list->next->next = new_node(7);
    list->next->next->next = new_node(8);
    list->next->next->next->next = new_node(5);
    list->next->next->next->next->next = new_node(9);
    list->next->next->next->next->next->next = new_node(2);
    list->next->next->next->next->next->next->next = new_node(1);

    int x = 5;

    displayList(list);
    printf("\n");
    list = partition_List(list,x);
    printf("Linked list after partition around %d\n",x);
    displayList(list);
}
