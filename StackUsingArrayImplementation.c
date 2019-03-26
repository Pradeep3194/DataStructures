//
// Created by Ilango, Pradeep on 2019-03-26.
//

#include <stdio.h>
#include <stdlib.h>

struct stack* createStack(int);
int isStackEmpty(struct stack*);
int isStackFull(struct stack*);
void push(struct stack*, int);
int pop(struct stack*);
void print(struct stack*);

int main() {
    int capacity;
    printf("Enter the capacity of the stack you want to create\n");
    scanf("%d", &capacity);
    struct stack* stack = createStack(capacity);
    if(isStackEmpty(stack)) {
        printf("Stack is Empty\n");
    }
    if(isStackFull(stack)) {
        printf("Stack is Full\n");
    }
    print(stack);
    push(stack, 1);
    print(stack);
    push(stack, 2);
    print(stack);
    push(stack, 3);
    print(stack);
    push(stack, 4);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    return 0;
}

struct stack {
    int* array;
    int top;
    int capacity;
};

struct stack* createStack(int capacity) {
    struct stack* newStack = (struct stack*)malloc(sizeof(struct stack));
    newStack -> capacity = capacity;
    newStack -> top = -1;
    newStack -> array = (int*)malloc(capacity* sizeof(int));
    return newStack;
}

int isStackEmpty(struct stack* stack) {
    if(stack->top == -1) {
        return 1;
    }
    return 0;
}

int isStackFull(struct stack* stack) {
    if(stack->top == (stack->capacity -1)) {
        return 1;
    }
    return 0;
}

void push(struct stack* stack, int value) {
    if(isStackFull(stack)) {
        printf("Stack is empty.cannot push\n");
        return;
    }
    (stack->top)++;
    stack->array[stack->top] = value;
}

int pop(struct stack* stack) {
    if(isStackEmpty(stack)) {
        printf("Stack is Empty. Could not pop\n");
        return -1;
    }
    int data = stack->array[stack->top];
    (stack->top)--;
    return data;
}

void print(struct stack* stack) {
    if(isStackEmpty(stack)) {
        printf("Stack is Empty\n");
        return;
    }
    int i;
    printf("The stack is : ");
    for(i=0;i<=(stack->top);i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

/**
 * Similar to real world such as stack of plates, Tennis Balls, Towers in towers of hanoi
 * Stack - collection/list of items. Insertion and deletion happens at one end known as top
 * Last In First Out Paradigm (LIFO)
 * Operations - Insertion(PUSH) , Deletion(POP), TOP, IsStackEmpty/Full - Constant time O(1).
 *
 * Applications:
 * 1. Function Calls/Recursion.
 * 2. Undo in an editor
 * 3. Compiler verifies Parenthesis Validation
**/