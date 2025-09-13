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

void to_array(int arr[],int n){
    struct Node *temp = stNode;
    int i = 0;

    while(temp != NULL){
        arr[i] = temp->num;
        i++;
        temp = temp->next;
    }
}

void main(){
    int n,s,pos;
    printf("Enter no. of Nodes: ");
    scanf("%d",&n);
    int arr[n];
    createNodeList(n);

    displayList();
    printf("\n");
    to_array(arr,n);
    printf("\n");
    for(int i = 0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");



}
