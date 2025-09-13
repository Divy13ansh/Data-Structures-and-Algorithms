#include<stdio.h>
#include<stdlib.h>

struct Node{
    int num;
    struct Node *next;
}*stNode;

void createNodeList(int n){
    stNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fnNode;
    struct Node *temp = stNode;
    if(stNode == NULL){
        printf("Memory is full");
        return;
    }
    else{
        printf("Enter data for Node 1: ");
        scanf("%d",&stNode->num);
        stNode->next = NULL;

        for(int i = 2;i<=n;i++){
            fnNode = (struct Node *)malloc(sizeof(struct Node));
            if(fnNode == NULL){
                printf("Memory is full");
                break;
            }
            printf("Enter data for Node %d: ",i);
            scanf("%d",&fnNode->num);
            fnNode->next = NULL;

            temp->next = fnNode;
            temp = temp->next;
        }
    }
}

void displayList(){
    struct Node *temp = stNode;
    while(temp!=NULL){
        printf("%d\t",temp->num);
        temp = temp->next;
    }
}

void prependNode(){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Memory is full");
    }
    printf("\nEnter data for new Node to prepend: ");
    scanf("%d",&temp->num);
    temp->next = stNode;
    stNode = temp;
}

void main(){
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    createNodeList(n);

    displayList();

    prependNode();

    displayList();
}
