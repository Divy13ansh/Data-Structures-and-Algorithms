#include<stdio.h>
#include<stdlib.h>
void main(){
    int* create(int);
    void disp(int*,int);
    int sum(int*,int);
    int search(int*,int,int);
    void insert(int*,int,int,int);
    void del(int*,int,int);
    int ch,k=1,size,p,s,i,pos,ele;
    while(k){
        printf("Menu\n1. Create\n2. Display\n3. Sum\n4. Search\n5. Insert\n6. Delete\n7. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter size: ");a
                scanf("%d",&size);

                p=create(size);
                break;
            case 2:
                disp(p,size);
                break;
            case 3:
                s=sum(p,size);
                printf("%d\n",s);
                break;
            case 4:
                printf("Enter searching element: ");
                scanf("%d",&s);
                i=search(p,size,s);
                if(i==-1)
                    printf("Element not found\n");
                else
                    printf("Element found at %d\n",i+1);
                break;
            case 5:
                printf("Enter position you want to insert at: ");
                scanf("%d",&pos);
                if(pos > size){
                    printf("Out of range\n");
                }
                else{
                    printf("Enter number to insert: ");
                    scanf("%d",&ele);
                    insert(p,size,pos,ele);
                }
                break;
            case 6:
                printf("Enter position you want to delete: ");
                scanf("%d",&pos);
                if(pos > size){
                    printf("Out of range\n");
                }
                else{
                    del(p,size,pos);
                }
                break;

            case 7:
                k=0;
                break;
            default:
                printf("Invalid Input");

            }
    }
}
int* create(int size){
    int i,*z;
    z=(int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++){
        printf("Enter element");
        scanf("%d",(z+i));
    }
    return z;

}
void disp(int *p,int size){
    int i;
    for(i=0;i<size;i++){
            printf("%d\t",*(p+i));
    }
    printf("\n");
}
int sum(int *p,int size){
    int i,s;
    for(i=0,s=0;i<size;i++){
        s=s+(*(p+i));
    }
    return s;
}
int search(int *p, int size, int s){
    int i,f;
    for(i=0,f=0;i<size;i++){
            if (s==(*(p+i))){
                f=1;
                break;
            }
    }
        if(f==0)
              return -1;
        else
            return i;
}
void insert(int *p,int size,int pos,int ele){
    int i,ch;
    printf("Chota Menu\n1. Usi ke upar likhdo\n2. Beech mein hi Ghusaa do\nEnter Your Choice: \n");
    scanf("%d",&ch);
    if(ch==1){
        *(p+(pos-1))=ele;
    }
    else{
        for(i=size-1;i>=pos;i--){
            *(p+i)=*(p+i-1);
        }
        *(p+(pos-1))=ele;
    }
}
void del(int *p,int size,int pos){
    int i,ch;
    printf("Menu\n1. Vahi 0\n2. Last mein 0\nEnter Your Choice");
    scanf("%d",&ch);
    if(ch==1){
        *(p+(pos-1))=0;
    }
    else{
        for(i=pos-1;i<size;i++){
            *(p+i)=*(p+i+1);
        }
        *(p+size-1)=0;
    }
}
