//
// Created by Ilango, Pradeep on 2019-03-27.
//

#include <stdio.h>
#include <stdlib.h>

struct queue* createQueue(int);
void enqueue(int, struct queue*);
int dequeue(struct queue*);
void front(struct queue*);
void rear(struct queue*);
int isFull(struct queue*);
int isEmpty(struct queue*);
void print(struct queue *);

struct queue {
    int capacity;
    int* array;
    int front;
    int rear;
};

struct queue* createQueue(int capacity) {
    struct queue* newQueue = (struct queue*) malloc(sizeof(struct queue));
    newQueue->capacity = capacity;
    newQueue->front = newQueue->rear = -1;
    newQueue->array = (int*)malloc(capacity * sizeof(int));
    return newQueue;
}

int main() {
    int capacity;
    printf("Enter the capacity of the Queue\n");
    scanf("%d", &capacity);
    struct queue* queue = createQueue(capacity);
    dequeue(queue);
    print(queue);
    print(queue);
    enqueue(5,queue);
    enqueue(3,queue);
    enqueue(2,queue);
    enqueue(1,queue);
    enqueue(8,queue);
    dequeue(queue);
    dequeue(queue);
    print(queue);
    printf("%d\n",dequeue(queue));
    enqueue(8,queue);
    print(queue);
    front(queue);
    rear(queue);
    return 0;
}

int isFull(struct queue* queue) {
    if((queue->rear + 1)%queue->capacity == queue->front) {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue* queue) {
    if((queue-> front == -1)) {
        return 1;
    }
    return 0;
}

void enqueue(int value, struct queue* queue) {
    if(isFull(queue)) {
        printf("Queue is Full\n");
        return;
    }
    if(queue->rear == -1) {
        queue->front++;
    }
    queue -> rear = ((queue->rear + 1)% (queue-> capacity));
    queue->array[queue-> rear] = value;
}

int dequeue(struct queue* queue) {
    int pop;
    if(isEmpty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    }
    pop=queue->array[queue->front];
    if(queue->rear == queue->front) {
        queue -> front = queue->rear = -1;
    }
    else {
        queue->front = (queue->front+1)% (queue-> capacity);
    }
    return pop;
}

void front(struct queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is Empty\n");
        return;;
    }
    printf("Front is %d \n", queue->array[queue->front]);
}
void rear(struct queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is Empty\n");
        return;;
    }
    printf("Rear is %d \n", queue->array[queue->rear]);
}

void print(struct queue * queue) {
    int i;
    if(isEmpty(queue)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("The Queue is: \n");
    if(queue->rear >= queue->front) {
        for(i=queue->front;i<=queue->rear;i++) {
            printf("%d ", (queue->array[i]));
        }
    }
    else {
        for(i=queue->front;i<queue->capacity;i++) {
            printf("%d ", (queue->array[i]));
        }
        for(i=0;i<=queue->rear;i++) {
            printf("%d ", (queue->array[i]));
        }
    }
    printf("\n");
}

/**
 * Similar to real world Queues.
 * First-In-first-out(FIFO)
 * Insertion happens at one end - Front/Head
 * Deletion happens at other end - Rear/Tail
 * Operations: Enqueue(Insertion) , Dequeue(Deletion), front(peek), rear(tail), isEmpty(), isFull() - Constant Time(O(1))
 * request served by shared resource - ex: Printer, Processor
 *
 * Front till Rear - Queue
 * Whichever end may be Front/Rear.
**/