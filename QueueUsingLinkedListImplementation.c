//
// Created by Ilango, Pradeep on 2019-03-27.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

struct node* createNode(int);
void enqueue(int, struct queue*);
int dequeue(struct queue*);
void front(struct queue*);
void rear(struct queue*);
struct queue* createQueue();

int main() {
    struct queue* queue = createQueue();
    enqueue(1,queue);
    front(queue);
    enqueue(2,queue);
    enqueue(3,queue);
    enqueue(4,queue);
    enqueue(5,queue);
    enqueue(6,queue);
    front(queue);
    rear(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    front(queue);
    rear(queue);
    return 0;
}

struct queue* createQueue() {
    struct queue* queue = (struct queue*) malloc(sizeof(struct queue));
    queue->front = queue->rear = NULL;
    return queue;
}

struct node* createNode(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = value;
    node->next = NULL;
    return node;
}

void enqueue (int value, struct queue* queue) {
    struct node* newNode = createNode(value);
    if(queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        (queue->rear)->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct queue* queue) {
    int pop;
    if(queue->front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    }
    pop = queue->front->data;
    if(queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
        return pop;
    }
    queue->front = (queue->front) -> next;
    return  pop;
}

void front(struct queue* queue) {
    printf("Front is %d\n", (queue->front)->data);
}

void rear(struct queue* queue) {
    printf("Rear is %d\n", (queue->rear)->data);
}