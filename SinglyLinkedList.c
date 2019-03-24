//
// Created by Ilango, Pradeep on 2019-03-23.
//

#include <stdio.h>
#include <stdlib.h>

struct node* createNode(int);
struct node* insertAtBeginning(struct node*,int);
struct node* insertAtPos(struct node*, int, int);
struct node* deleteAtPos(struct node*,int);
struct node* reverse(struct node*);
void printList(struct node*);
void printListRecursion(struct node*);
void reversePrint(struct node*);
int length(struct node*);
void reverseUsingRecursion(struct node**, struct node*);


struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* head = NULL;
    printf("Singly Linked List\n");
    printList(head);
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 6);
    head = insertAtBeginning(head, 7);
    head = insertAtBeginning(head, 8);
    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 2);
    printList(head);
    head = insertAtPos(head, 12, -1);
    head = insertAtPos(head, 13, 0);
    head = insertAtPos(head, 14, 1);
    head = insertAtPos(head, 12, 19);
    head = insertAtPos(head, 21, 4);
    head = insertAtPos(head, 22, 4);
    printList(head);
    head = deleteAtPos(head, -2);
    head = deleteAtPos(head, 19);
    head = deleteAtPos(head, 3);
    printList(head);
    head = deleteAtPos(head, 1);
    printList(head);
    head = reverse(head);
    printList(head);
    printListRecursion(head);
    reversePrint(head);
    reverseUsingRecursion(&head, head);
    printList(head);
    return 0;
}

struct node* createNode(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = value;
    node->next = NULL;
    return node;
}

struct node* insertAtBeginning(struct node* head, int value) {
    struct node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

struct node* insertAtPos(struct node* head, int value, int pos) {
    int i;
    struct node* temp = head;
    struct node* newNode = NULL;

    if((pos < 0) || ((pos > length(head) - 1))) {
        printf("Invalid Position\n");
        return head;
    }

    if(head == NULL) {
        head = insertAtBeginning(head, value);
    }


    for (i=0; i< (pos - 1); i++) {
        temp =temp-> next;
    }

    newNode = createNode(value);
    newNode-> next = temp->next;
    temp-> next = newNode;

    return head;
}

struct node* deleteAtPos(struct node* head, int pos) {
    int i =0;
    struct node* temp = head;
    struct node* deleteNode = NULL;
    if(head == NULL) {
        printf("List is empty");
        return head;
    }
    if((pos < 0) || (pos > (length(head)-1))) {
        printf("Invalid Position\n");
        return head;
    }

    if(pos == 0) {
        head = head -> next;
        free(temp);
        return head;
    }

    for(i =0; i<(pos -1); i++) {
        temp = temp -> next;
    }
    deleteNode = temp -> next;
    temp->next = deleteNode -> next;
    free(deleteNode);
    return head;

}

struct node* reverse(struct node* head) {
    struct node* current;
    struct node* next;
    struct node* prev = NULL;
    current = head;
    while(current!= NULL) {
        next = current-> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void reverseUsingRecursion(struct node** head, struct node* node){
    if(node-> next ==NULL) {
        (*head) = node;
        return;
    }
    reverseUsingRecursion(head,node->next);
    node ->next->next = node;
    node->next = NULL;
}

int length(struct node* head) {
    int length = 0;
    while(head!= NULL) {
        length++;
        head = head->next;
    }
    return length;
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

void printListRecursion(struct node* head) {
    if(head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head->data);
    printListRecursion(head->next);
    return;
}

void reversePrint(struct node* head) {
    if(head == NULL) {
        return;
    }
    reversePrint(head-> next);
    printf("%d ", head->data);
    return;
}

/**
 * One Unit of memory at a time. Non Contiguous Memory Block.
 * Unit/Node - data, (pointer) address of next element.
 * Fisrt Node - Head Node. We keep its address to traverse the list.
 * Last Node - Pointer null to indicate the end.
 * Head Node - Pointer to first Node
 *
 * Pros:
 * No Memory wastage.
 * Always gets a block if memory available
 * Extending/Reducing - O(1)
 * Insert/Delete at end/begin - O(1)
 * No shifting for Insert. Just Traversal is required
 *
 * Cons:
 * Access - O(n)
 * Insert/Delete at pos - O(n)
 * Extra memory for Pointer.
 * Not ease of Implementation. error prone - segmentation fault, memory leak.
**/