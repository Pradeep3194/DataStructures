//
// Created by Ilango, Pradeep on 2019-03-26.
//

#include <stdio.h>
#include <stdlib.h>

struct node* createNode(int);
struct node* push(struct node*, int);
struct node* pop(struct node*);
void print(struct node*);

struct node {
    int data;
    struct node* next;
};

struct node* push(struct node* top, int data) {
    struct node* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
    return top;
}

struct node* pop(struct node* top) {
    if(top == NULL) {
        printf("Stack is Empty\n");
        return top;
    }
    struct node* temp = top;
    top = top-> next;
    free(temp);
    return top;
}

void print(struct node* top) {
    if(top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    printf("The Stack is : ");
    while(top!=NULL) {
        printf("%d ", top-> data);
        top = top->next;
    }
    printf("\n");
    return;
}

struct node* createNode(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = value;
    node->next = NULL;
    return node;
}

int main() {
    struct node* top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    top =push(top, 6);
    print(top);
    top = pop(top);
    print(top);
    top = pop(top);
    print(top);
    top = pop(top);
    print(top);
    top = pop(top);
    print(top);
    top = pop(top);
    print(top);
    top = pop(top);
    print(top);
    top = pop(top);
    print(top);
    return 0;
}