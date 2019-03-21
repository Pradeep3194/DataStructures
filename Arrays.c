#include<stdio.h>

#define SIZE 256

int isFull();
int isEmpty();
int insertAt(int[],int,int,int);
void printArray(int[], int);
void getLength(int top);
int delete(int[], int, int);

int main() {
    int a[SIZE];
    int top = -1;

    printf("Is Array Full: %d\n", isFull(top));
    printf("Is Array Empty: %d\n", isEmpty(top));
    getLength(top);
    top = insertAt(a, top, -2, 5);
    top = insertAt(a, top, 3494, 5);
    top = insertAt(a, top, 2 , 5);
    top = insertAt(a, top, 0 , 5);
    printArray(a, top);
    top = insertAt(a, top, 1 , 7);
    top = insertAt(a, top, 2 , 8);
    getLength(top);
    top = insertAt(a, top, 3 , 9);
    top = insertAt(a, top, 1 , 6);
    printArray(a, top);
    getLength(top);
    top = delete(a, 2, top);
    printArray(a, top);
    getLength(top);
    top = delete(a, 289, top);
    return 0;
}

int isFull(int top) {
  if(top == (SIZE - 1)) {
        return 1;
  }
  return 0;
}

int isEmpty(int top) {
   if(top == -1) {
        return 1;
   }
   return 0;
}

int insertAt(int a[], int top, int pos, int value) {
    if(isFull(top)) {
        printf("Array is full. cannot insert\n");
        return top;
    }
    if((pos > (top+1)) || (pos < 0)) {
        printf("Invalid Position\n");
        return top;
    }
    for (int j=top ; j>=pos ; j--) {
        a[j+1] = a[j];
    }
    a[pos] = value;
    top++;
    return top;
}

void printArray(int a[], int top) {
    if(isEmpty(top)) {
        printf("Array is Empty\n");
        return;
    }
    printf("Array is:\n");
    for(int i=0; i<=top; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void getLength(int top) {
    if(isEmpty(top)) {
        printf("Array is empty\n");
        return;
    }
    printf("Length of the Array is : %d\n", top + 1);
}

int delete(int a[], int pos, int top) {
    if(isEmpty(top)) {
        printf("Invalid Position\n");
        return top;
    }
    if((pos > top) || (pos < 0)) {
        printf("Invalid Position\n");
        return top;
    }
    for(int j=pos; j<top; j++) {
        a[j] = a[j+1];
    }
    return top-1;
}
