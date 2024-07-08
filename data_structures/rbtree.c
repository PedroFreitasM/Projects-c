#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int key;
    bool color;
    //1 = red, 0 = black
    struct node* left;
    struct node* right;
    struct node* parent;
}rbNode;

rbNode* createNode(int key, bool color);
int insertRBTree(int num, rbNode** root);
void fixTree(rbNode** root, rbNode* node);
void leftRotate(rbNode** root, rbNode* node);
void rightRotate(rbNode** root, rbNode* node);
void printTree(rbNode* root);

int main(){
    int num;
    char op;
    rbNode* tree = NULL;
    while(scanf(" %c", &op) == 1){
        if(op == 'i'){
            scanf("%d", &num);
        }
        switch(op){
            case 'i':
                insertRBTree(num, &tree);
                break;
            case 'p':
                printTree(tree);
                break;
            default:
                printf("Wrong command\n");
        }
    }
    return 0;
}

rbNode* createNode(int key, bool color){
    rbNode* newNode = (rbNode*)malloc(sizeof(rbNode));
    newNode->key = key;
    newNode->color = color;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}


int insertRBTree(int num, rbNode** root){
    rbNode* node = createNode(num, true);
    if (*root == NULL){
        node->color = false;
        *root = node;
        return 0;
    }
    rbNode* previous = NULL;
    rbNode* current = *root;
    while(current != NULL){
        previous = current;
        if(num < current->key){
            current = current->left;
        }else if(num > current->key){
            current = current->right;
        }else{
            free(node);
            printf("Number already in tree");
            return 1;
        }
    }
    node->parent = previous;
    if(num < previous->key){
        previous->left = node;
    }else{
        previous->right = node;
    }
    fixTree(root, node);
    return 0;
}

void fixTree(rbNode** root, rbNode* node){
    rbNode* parent = NULL;
    rbNode* grandparent = NULL;
    while ((node != *root) && (node->color != false) && (node->parent->color == true)){
        parent = node->parent;
        grandparent = node->parent->parent;
        if (parent == grandparent->left){
            rbNode* uncle = grandparent->right;
            if (uncle != NULL && uncle->color == true){
                grandparent->color = true;
                parent->color = false;
                uncle->color = false;
                node = grandparent;
            } else {
                if (node == parent->right){
                    leftRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }
                rightRotate(root, grandparent);
                bool tempColor = parent->color;
                parent->color = grandparent->color;
                grandparent->color = tempColor;
                node = parent;
            }
        } else {
            rbNode* uncle = grandparent->left;
            if (uncle != NULL && uncle->color == true){
                grandparent->color = true;
                parent->color = false;
                uncle->color = false;
                node = grandparent;
            } else {
                if (node == parent->left){
                    rightRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }
                leftRotate(root, grandparent);
                bool tempColor = parent->color;
                parent->color = grandparent->color;
                grandparent->color = tempColor;
                node = parent;
            }
        }
    }
    (*root)->color = false;
}

void leftRotate(rbNode** root, rbNode* node){ // the root pointer is here so that, if the root is rotated, the pointer doesnt go wild
    rbNode* temp = node->right;
    node->right = temp->left;
    if(temp->left != NULL) temp->left->parent = node;
    temp->parent = node->parent;
    if(node->parent == NULL){ *root = temp;
    }else if (node == node->parent->left){
        node->parent->left = temp;
    }else{
        node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}

void rightRotate(rbNode** root, rbNode* node){
    rbNode* temp = node->left;
    node->left = temp->right;
    if (temp->right != NULL) temp->right->parent = node;

    temp->parent = node->parent;
    if(node->parent == NULL) *root = temp;
    else if (node == node->parent->left) node->parent->left = temp;
    else node->parent->right = temp;
    temp->right = node;
    node->parent = temp;
}

void printTree(rbNode* root){
    if (root == NULL) return;
    printf("%d", root->key);
    if (root->color == true) printf("R ");
    else printf("N ");
    printTree(root->left);
    printTree(root->right);
}


