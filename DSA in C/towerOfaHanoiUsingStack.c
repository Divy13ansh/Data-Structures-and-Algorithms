#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

struct Stack
{
    unsigned capacity;
    int top;
    int *array;
};

//Creating Stack
struct Stack* createStack(unsigned capacity){
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
}


//returns true if top == capacity-1(stack is full)
int isFull(struct Stack *stack){
    return(stack->top == stack->capacity-1);
}

//returns true if top == -1(stack is empty)
int isEmpty(struct Stack *stack){
    return(stack->top == -1);
}

//pushes element into the stack
void push(struct Stack *stack, int item){
    if(stack->top == stack->capacity-1){
        return;
    }
    stack->array[++stack->top] = item;
}

//pops element from the stack
int pop(struct Stack *stack){
    if(stack->top == -1){
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

//Displays the movement
void moveDisk(char fromPeg, char toPeg, int disk){
    printf("\nMove disk %d from %c to %c", disk, fromPeg, toPeg);
}

void moveDiskBetweenTwoPoles(struct Stack *src, struct Stack *dest, char s, char d){
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);

    if(pole1TopDisk == INT_MIN){ // pole 1 khaali hy to pole 1 me pole 2 ki top disk daal do.
        push(src, pole2TopDisk);
        moveDisk(d,s,pole2TopDisk);
    }

    else if(pole2TopDisk == INT_MIN){ // pole 2 khaali hy to pole 2 me pole 1 ki top disk daal do.
        push(dest,pole1TopDisk);
        moveDisk(s,d,pole1TopDisk);
    }

    else if(pole1TopDisk > pole2TopDisk){
        push(src,pole1TopDisk);
        push(src,pole2TopDisk);
        moveDisk(d,s,pole2TopDisk);
    }

    else{
        push(src,pole2TopDisk);
        push(src,pole1TopDisk);
        moveDisk(s,d,pole1TopDisk);
    }
}

void tohIterative(int num_of_disks, struct Stack *src, struct Stack *aux, struct Stack *dest){
    int i,total_num_of_moves;
    char s = 'S', d = 'D', a = 'A';
    if(num_of_disks % 2 == 0){
        char temp = d;
        d = a;
        a = temp;
    }

    total_num_of_moves = pow(2,num_of_disks)-1;

    for(i = num_of_disks; i >= 1; i--){
        push(src,i);
    }

    for(i = 1;i <= total_num_of_moves; i++){
        if(i % 3 == 1){
            moveDiskBetweenTwoPoles(src,dest,s,d);
        }

        else if(i % 3 == 2){
            moveDiskBetweenTwoPoles(src,aux,s,a);
        }
        
        else if(i % 3 == 0){
            moveDiskBetweenTwoPoles(aux,dest,a,d);
        }
    }


}

void main(){
    unsigned num_of_disks = 3;
    struct Stack *src, *dest, *aux;

    src = createStack(num_of_disks);
    aux = createStack(num_of_disks);
    dest = createStack(num_of_disks);

    tohIterative(num_of_disks,src,aux,dest);
}