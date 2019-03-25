//
// Created by Ilango, Pradeep on 2019-03-24.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(int);
struct node* insertAtHead(struct node*,int);
void printList(struct node*);
void printListReverse(struct node*);

int main() {
    struct node* head = NULL;
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    printList(head);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    printList(head);
    printListReverse(head);
    return 0;
}

struct node* createNode(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct node* insertAtHead(struct node* head,int value) {
    struct node* newNode = createNode(value);
    if(head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

void printList(struct node* head) {
    if(head == NULL) {
        printf("List is Empty \n");
        return;
    }
    printf("\nThe List is: ");
    while(head!=NULL) {
        printf("%d ", head->data);
        head = head-> next;
    }
    printf("\n");
    return;
}

void printListReverse(struct node* head) {
    if(head == NULL) {
        printf("List is Empty\n");
        return;
    }
    while(head->next!=NULL) {
        head = head->next;
    }
    printf("The Reverse List is: ");
    while(head!=NULL) {
        printf("%d ",head->data);
        head = head->prev;
    }
}

/**
 * prev and next pointers that allow both way traversal
 * lot of operations becomes easier when we have previous pointer. ex: delete a node, reversal
 *
 * Cons:
 * Extra memory
 * Update 2 pointers for operations
**/