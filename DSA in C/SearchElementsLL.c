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
    temp = stNode;

    printf("Enter data for node 1: ");
    scanf("%d",&stNode->num);
    stNode->next = NULL;

    for(int i = 2;i<=n;i++){
        struct Node *fnNode;
        fnNode = (struct Node *)malloc(sizeof(struct Node));
        if(fnNode == NULL){
            printf("Memory is full");
            break;
        }

        printf("Enter data for node %d: ",i);
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

int search_ele(int n){
    struct Node *temp = stNode;

    int c = 0;
    while(temp != NULL){
        c++;
        if(temp->num == n){
            return c;
        }
        temp = temp->next;
    }
}

void main(){
    int n,s,pos;
    printf("Enter no. of Nodes: ");
    scanf("%d",&n);

    createNodeList(n);
    displayList();
    printf("\n");

    printf("Enter the element you want to search: ");
    scanf("%d",&s);

    printf("\n");

    pos = search_ele(s);
    printf("%d",pos);
}
