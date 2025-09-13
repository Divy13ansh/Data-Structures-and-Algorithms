#include<stdio.h>

struct Node{
    int num;
    struct Node *next;
}*stNode;

void createNodeList(n){
    stNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fnNode, *temp;
    temp = stNode;
    if(stNode == NULL){
       printf("Memory is full");
       return;
    }
    else{
        printf("Enter the data for node 1: ");
        scanf("%d",&stNode->num);
        stNode->next = NULL;

        for(int i = 2;i<=n;i++){
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
}

void midins(int n){
    struct Node *temp, *fnNode;
    int i = 1;
    temp = stNode;
    int num;

    fnNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for the new node: ");
    scanf("%d",&fnNode->num);

    while(i < n-1){
        temp = temp->next;
        i++;
    }
    fnNode->next = temp->next->next;
    temp->next = fnNode;

}

void displayList(){
    struct Node *temp = stNode;

    while(temp != NULL){
        printf("%d\t",temp->num);
        temp = temp->next;
    }
}


void main(){
    int n,m;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    createNodeList(n);

    displayList();

    printf("\nWhere do you want to insert the node: ");
    scanf("%d",&m);

    midins(m);

    displayList();
}
