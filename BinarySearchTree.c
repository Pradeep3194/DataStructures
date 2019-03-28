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

struct BstNode* insert(struct BstNode*,int);
struct BstNode* createNode(int);
int search(struct BstNode*,int);
int min(struct BstNode*);
int max(struct BstNode*);
int height(struct BstNode*);

int main() {
    struct BstNode* root = NULL;
    root=insert(root,5);
    root=insert(root, 10);
    root=insert(root,3);
    root=insert(root,2);
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
    return 0;
}

struct BstNode* createNode(int value) {
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

struct BstNode* insert(struct BstNode* root, int value) {
    if(root == NULL) {
        return createNode(value);
    } else if(value<= root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
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
**/