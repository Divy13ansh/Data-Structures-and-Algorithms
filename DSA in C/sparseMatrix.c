#include<stdio.h>
#include<stdlib.h>
#define ROW 4
#define COL 5
struct sparse{
    int *sp;
    int row;
};
void main(){
    void create_mat(struct sparse *);
    void disp_mat(struct sparse);
    int count(struct sparse);
    void create_tuple(struct sparse, struct sparse *);
    void disp_tuple(struct sparse);
    struct sparse A,B;
    int i,j,k=1,ch;
    while(k){
        printf("\nMenu\n1. Create Matrix\n2. Display\n3. Count\n4. Create Tuple\n5. Display Tuple\n6. Exit\nEnter Your Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                create_mat(&A);
                break;
            case 2:
                disp_mat(A);
                break;
            case 3:
                i = count(A);
                printf("%d",i);
                break;
            case 4:
                create_tuple(A,&B);
                break;
            case 5:
                disp_tuple(B);
            case 6:
                k = 0;
                break;
        }
    }
}

void create_mat(struct sparse *p){
    p->sp = (int *)malloc(sizeof(int)*(ROW*COL));
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("Enter ele: ");
            scanf("%d",p->sp+(i*COL)+j);
        }
    }
}

void disp_mat(struct sparse x){
    int i;
    for(i=0;i<(ROW * COL);i++){
        if(i%COL == 0)
            printf("\n");
        printf("%d\t",*(x.sp+i));
    }
}

int count(struct sparse x){
    int i,c=0;
    for(i=0;i<(ROW * COL);i++){
        if(*(x.sp+i) != 0)
            c++;
    }
    return c;
}

void create_tuple(struct sparse X, struct sparse *y){
    int i,k,r,c;
    y->row = count(X)+1;
    y->sp = (int *)malloc(sizeof(int)*(y->row*3));
    *(y->sp+0) = ROW;
    *(y->sp+1) = COL;
    *(y->sp+2) = (y->row)-1;
    k = 3;
    r = -1;
    c = -1;
    for(i=0;i<(ROW*COL);i++){
        c++;
        if(i%COL == 0){
            r++;
            c=0;
        }
        if(*(X.sp+i)!=0){
            *(y->sp+k) = r;
            k++;
            *(y->sp+k) = c;
            k++;
            *(y->sp+k) = *(X.sp+i);
            k++;
        }
    }
}

void disp_tuple(struct sparse y){
    int i;
    for(i=0;i<(y.row)*3;i++){
            if(i%3 == 0){
                printf("\n");
            }
            printf("%d\t",*(y.sp+i));
    }
}
