#include<stdio.h>

struct Node{
    int num;
    struct Node *next;
}*stNode;


void createNodeList(n){
    stNode = (struct Node *)malloc(sizeof(struct Node));
    if(stNode == NULL){
        printf("Memory is Full");
        return;
    }
    struct Node *temp;
    printf("Enter data for Node 1: ");
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
        printf("Enter data for Node %d: ",i);
        scanf("%d",&fnNode->num);
        fnNode->next = NULL;

        temp->next = fnNode;
        temp = temp->next;
    }
}

void midDeletion(){
    int n;
    struct Node *t;
    struct Node *temp = stNode;

    printf("Enter the no. of element you want to delete: ");
    scanf("%d",&n);

    for(int i = 0; i<n-2 && temp != NULL;i++,temp = temp->next){}

    t = temp->next;
    temp->next = t->next;
    free(t);
}

void displayList(){
    struct Node *temp = stNode;
    while(temp!=NULL){
        printf("%d\t",temp->num);
        temp = temp->next;
    }
}

void main(){
    int n;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    createNodeList(n);
    printf("\n");
    displayList();
    printf("\n");
    midDeletion();
    printf("\n");
    displayList();
}
