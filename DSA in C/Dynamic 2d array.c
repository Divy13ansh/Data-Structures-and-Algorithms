#include <stdio.h>
void main(){
    int *create(int,int);
    void disp(int *,int,int);
    int search(int *,int,int,int,int*,int*);
    void insert(int*,int,int,int);
    void del(int*,int,int);
    int i,j,m,n,k=1,pos,ele,s,row,col,ch,p,size;
    while(k){
        printf("Menu\n1. Create\n2. Display\n3. Sum\n4. Search\n5. Insert\n6. Delete\n7. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter no. of rows and columns: ");
                scanf("%d%d",&m,&n);
                p=create(m,n);
                break;
            case 2:
                disp(p,m,n);
                break;
            case 3:
                printf("Enter searching element: ");
                scanf("%d",&s);
                i=search(p,m,n,s,&row,&col);
                if(i==-1)
                    printf("Not found");
                else
                    printf("Found at %d row and %d col",row+1,col+1);
                break;
            case 4:
                printf("Enter row and column you want to insert at: ");
                scanf("%d%d",&row,&col);
                if(row>m||col>n){
                    printf("Out of reach");
                }
                else{
                    printf("Enter new element: ");
                    scanf("%d",&ele);
                    pos=((row-1)*n+(col-1));
                    size=m*n;
                    insert(p,size,pos,ele);
                }
                break;
        }
    }
}
int *create(int m,int n){
    int *z,int i,int j;
    z=(int*)malloc(sizeof(int)*(m*n));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter element");
            scanf("%d",&z+((i*n)+j));
        }
    }
    return z;
}
void disp(int *p,int m,int n){
    int i;
    for(i=0;i<(m*n);i++){
        if(i%n=0)
            printf("\n");
        printf("%d\t",*(p+i));
    }
}
int search(int *p,int m,int n,int s,int &x,int &y){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(*(p+(i*n)+j)=s){
                *x=i;
                *y=j;
                return 1;
            }
        }
    }
    return -1;
}
void insert(int*p,int s,int pos,int ele){
    int ch;
    printf("1. Overwrite\n2. Shift\nEnter your choice: ")
    scanf("%d",ch);
    if(ch==1){
        *(p+pos)=ele;
    }
    else{
        for(i=size-1;i>)
    }
}
