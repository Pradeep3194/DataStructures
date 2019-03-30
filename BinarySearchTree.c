//
// Created by Ilango, Pradeep on 2019-03-28.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct node {
    struct BstNode* data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

struct BstNode* insert(struct BstNode*,int);
struct BstNode* createBstNode(int);
int search(struct BstNode*,int);
struct BstNode* searchAndGetNode(struct BstNode*,int);
int min(struct BstNode*);
int max(struct BstNode*);
int height(struct BstNode*);
void bfs(struct BstNode*);
void preorder(struct BstNode*);
void postorder(struct BstNode*);
void inorder(struct BstNode*);
struct BstNode* delete(struct BstNode*,int);
struct BstNode* getMin(struct BstNode*);
struct BstNode* inorderSuccessor(struct BstNode*,int);

//Queue
struct node*  createNode(struct BstNode*);
void enqueue(struct BstNode*, struct queue*);
struct BstNode*  dequeue(struct queue*);
void front(struct queue*);
void rear(struct queue*);
struct queue* createQueue();
int isQueueEmpty(struct queue*);
int isBst(struct BstNode*);
int isBstUtil(struct BstNode*, int,int);

int main() {
    struct BstNode* root = NULL;
    root=insert(root,5);
    root=insert(root, 10);
    root=insert(root,3);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,4);
    root=insert(root,7);
    root=insert(root,8);
    printf("%d\n",search(root,7));
    printf("%d\n",search(root,3));
    printf("%d\n",search(root,3));
    printf("%d\n",search(root,24));
    printf("Minimum element is %d\n",min(root));
    printf("Maximum element is %d\n",max(root));
    printf("Height of the tree is %d\n",height(root));
    bfs(root);
    printf("Preorder of BST is : ");
    preorder(root);
    printf("\n");
    delete(root,7);
    printf("Postorder of BST is : ");
    postorder(root);
    printf("\n");
    delete(root,4);
    printf("Inorder of BST is : ");
    inorder(root);
    printf("\n");
    printf("Is Given tree is BST: %d\n",isBst(root));
    printf("InorderSuccessor of 4 is : %d\n",inorderSuccessor(root,4)->data);
    printf("InorderSuccessor of 5 is : %d\n",inorderSuccessor(root,5)->data);
    return 0;
}

struct BstNode* createBstNode(int value) {
    struct BstNode* newNode = (struct BstNode*) malloc(sizeof(struct BstNode));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int search(struct BstNode* root,int value) {
    if(root == NULL) {
        return 0;
    } else if(root->data == value) {
        return 1;
    } else if (value<=root->data) {
        return search(root->left,value);
    }
    return search(root->right,value);
}

struct BstNode* searchAndGetNode(struct BstNode* root,int value) {
    if(root == NULL) {
        return NULL;
    } else if(root->data == value) {
        return root;
    } else if (value<=root->data) {
        return searchAndGetNode(root->left,value);
    }
    return searchAndGetNode(root->right,value);
}

struct BstNode* insert(struct BstNode* root, int value) {
    if(root == NULL) {
        return createBstNode(value);
    } else if(value<= root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorder(struct BstNode* root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct BstNode* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorder(struct BstNode* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int min(struct BstNode* root) {
    if(root == NULL) {
        printf("Tree is Empty\n");
        return -1;
    }
    while(root->left!=NULL) {
        root=root->left;
    }
    return root->data;
}

int max(struct BstNode* root) {
    if(root==NULL) {
        printf("Tree is Empty\n");
        return -1;
    } else if(root->right==NULL) {
        return root->data;
    }
    return max(root->right);
}

int height(struct BstNode* root) {
    if(root == NULL) {
        return -1;
    }
    if(height(root->left) >height(root->right)) {
        return 1+(height(root->left));
    }
    return 1+height(root->right);
}

void bfs(struct BstNode* root) {
    struct BstNode* current = NULL;
    if(root == NULL) {
        printf("Tree is Empty\n");
        return;
    }
    struct queue* queue = createQueue();
    enqueue(root, queue);
    printf("The Tree in BFS is: ");
    int count =0;
    while(!isQueueEmpty(queue)) {
        current = dequeue(queue);
        printf("%d ",current->data);
        if(current->left!=NULL) {
            enqueue(current->left , queue);
        }
        if(current->right!=NULL) {
            enqueue(current->right , queue);
        }
        count ++;
    }
    printf("\n");
}


struct queue* createQueue() {
    struct queue* queue = (struct queue*) malloc(sizeof(struct queue));
    queue->front = queue->rear = NULL;
    return queue;
}

struct node*  createNode(struct BstNode*  value) {
    struct node*  node = (struct node* )malloc(sizeof(struct node));
    node-> data = value;
    return node;
}

void enqueue (struct BstNode* value, struct queue* queue) {
    struct node*  newNode = createNode(value);
    if(queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        (queue->rear)->next = newNode;
        queue->rear = newNode;
    }
}

struct BstNode* dequeue(struct queue* queue) {
    struct BstNode*  pop;
    if(queue->front == NULL) {
        printf("Queue is Empty\n");
        return NULL;
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
    printf("Front is %p\n", (queue->front)->data);
}

void rear(struct queue* queue) {
    printf("Rear is %p\n", ((queue->rear)->data));
}

int isQueueEmpty(struct queue* queue) {
    if(queue->front ==NULL) {
        return 1;
    }
    return 0;
}

int isBst(struct BstNode* root) {
    return isBstUtil(root,INT32_MIN,INT32_MAX);
}

int isBstUtil(struct BstNode* root, int min,int max) {
    if(root == NULL) {
        return 1;
    }
    else if(((root->data>min)&&(root->data<=max)) && isBstUtil(root->left, min,root->data) &&
        isBstUtil(root->right, root->data, max)) {
        return 1;
    }
    return 0;
}

struct BstNode* delete(struct BstNode* root, int value) {
    struct BstNode* temp;
    if(root == NULL) {
        return NULL;
    }
    else if(value < root->data) {
        root->left = delete(root->left, value);
    } else if(value > root->data) {
        root->right = delete(root->right, value);
    } else {
        if(root->left == NULL && root->right==NULL) {
            free(root);
            root = NULL;
        } else if(root->left == NULL) {
            temp = root;
            root = root->right;
            free(temp);
        } else if(root->right == NULL) {
            temp = root;
            root = root->left;
            free(temp);
        } else {
            root->data = (getMin(root->right))->data;
            delete(root->right, root->data);
        }
    }
    return root;
}

struct BstNode* getMin(struct BstNode* root) {
    if(root == NULL) {
        return NULL;
    }
    while(root->left!=NULL) {
        root = root->left;
    }
    return root;
}

struct BstNode* inorderSuccessor(struct BstNode* root, int value) {
    struct BstNode* current = searchAndGetNode(root,value);
    struct BstNode* ancestor;
    struct BstNode* successor =NULL;
    if(current == NULL) return NULL;
    if(current->right!=NULL) {
        return getMin(root->right);
    } else {
        ancestor = root;
        while(ancestor!=current) {
            if(value<ancestor->data) {
                successor =ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
    }
    return successor;
}

/**
 * TREES:
 * Trees - Recursive Non Linear Data structure.
 * Hierarchical Structure.
 * Root - Topmost Node.
 * Parent, children
 * sibiling - children of same parent
 * Internal Node - node with atleast 1 child
 * Leaf Node - Node with no children
 * Ancestor, Descendent
 * Grand Parent - Parent of Parent
 * Cousins - same grand parent but not same parent
 * Uncle - parent's sibiling
 * Tree with 'n' nodes has exactly 'n-1' edges.
 * Depth of node - length of path from root to node.
 * Height of node - number of edges in longest path from that node to leaf node.
 * Height of the Tree - Height of root node.
 * Height and depth of a node may not be same
 * Binary Tree - Tree with node having atmost 2 children.
 * Strict/Proper Binary Tree - Nodes with Zero or 2 children.
 * Complete Binary Tree - All levels except the last are completely filled and all nodes are as left as possible.
 * Nodes at same depth are at same level.
 * Maximum Depth of a tree = Height
 * Maximum no of nodes at level i = 2^i
 * Perfect - All levels are completely filled.
 * Max no of nodes in tree with height h = 2^0 + 2^1 + .. +2^h = (2^(h+1)) -1 (G.P)
 * Mostly Cost of any operations in a tree = Height of the Tree.
 * Min Hieght - Logn
 * Max Height - n-1
 * k-balanced binary tree - diff between height(left subtree) and height(right subtree) should not be more than k
 *Height (empty tree) - -1
 *
 * Binary Tree Implementation - Most cases Dynamically linked nodes.
 *                              Some Special cases by array mostly for Complete Binary Trees: left child(i) = 2*i,
 *                              right child(i) = (2*i)+1.
 *
 *
 * Applications:
 * 1. Storing Naturally Hierarchical Data - File System
 * 2. BST for quick search, insert, delete.
 * 3. Tries - dynamic spell checking
 *
 *
 * BINARY SEARCH TREE:
 * Binary tree in which value of all nodes in left subtree are lesser than node value
 * and value of all nodes in right subtree are greater than node value.
 * Insert,Delete and Search - O(logn)
 *
 *
 * Tree Traversal:
 *   Process of visiting each node one time
 * Types: Breadth-First-Search(BFS) and Depth-First-Search(DFS)
 * BFS: (level order traverlsal)
 *    visiting all nodes at same level(left to right). visit all the children before visiting grand children
 * DFS:
 *    visit all sutree of a child and then move to next child. Relative order can be different.
 *    RootLR(Preorder), LRRoot(PostOrder), LRootR(Inorder).
 *
 * Inorder Traversal of BST - Sorted List.
**/