#include<stdio.h>

struct Node{
    int num;
    struct Node *next;
}*stNode;

void createNodeList(int n){
    struct Node *temp;
    stNode = (struct Node *)malloc(sizeof(struct Node));
    if(stNode == NULL){
        printf("Memory is full");
        return;
    }
    printf("Enter the data for node 1: ");
    scanf("%d",&stNode->num);
    stNode->next = NULL;
    temp = stNode;

    for(int i = 2;i<=n;i++){
        struct Node *fnNode;
        fnNode = (struct Node *)malloc(sizeof(struct Node));
        if(fnNode == NULL){
            printf("Memory is full");
            break;
        }

        printf("Enter the data for node %d: ",i);
        scanf("%d",&fnNode->num);
        fnNode->next = NULL;

        temp->next = fnNode;
        temp = temp->next;
    }
}

void displayList(){
    struct Node *temp = stNode;

    while(temp != NULL){
        printf("%d\t",temp->num);
        temp = temp->next;
    }
}

void deleteTail(){
    struct Node *temp = stNode;
    struct Node *t;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    t = temp->next;
    temp->next = NULL;
    free(t);
}

void main(){
    int n;
    printf("Enter the no. of nodes in the list: ");
    scanf("%d",&n);

    createNodeList(n);

    displayList();
    printf("\n");

    deleteTail();
    printf("\n");

    displayList();

}
