#include <stdio.h>
#include <stdlib.h>

typedef struct aux1{
    int key;
    struct aux1 *left;
    struct aux1 *right;
}treeNode;

treeNode* createNode(int num);
int insertTree(treeNode** root, int num);
int removeTree(treeNode** root, int num);
void printTree(treeNode* root);
treeNode* createNode(int num);

int main(){
    char op;
    int num;
    treeNode* root = NULL;
    while(scanf(" %c",&op) == 1){
        if(op == 'i' || op == 'r'){
            scanf("%d", &num);
        }
        switch (op){
        case 'i':
            insertTree(&root, num);
            break;
        case 'r':
            removeTree(&root, num);
            break;
        case 'p':
            printTree(root);
            printf("\n");
            break;
        default:
            printf("Wrong command\n");
        }
    }
    return 0;
}

treeNode* createNode(int num){
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->key = num;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int insertTree(treeNode** root, int num){
    treeNode* node = createNode(num);
    if(*root == NULL){
        *root = node;
        return 1;
    }

    if (num == (*root)->key){
        printf("Number already in tree");
        return 0;
    }

    if (num < (*root)->key){
        return insertTree(&((*root)->left), num);
    }
    return insertTree(&((*root)->right), num);
}

int removeTree(treeNode** root, int num){
    if (*root == NULL){
        printf("Number not in tree\n");
        return 0;
    }

    if (num < (*root)->key){
        return removeTree(&((*root)->left), num);
    }
    if (num > (*root)->key){
        return removeTree(&((*root)->right), num);
    }

    treeNode* temp;
    if((*root)->left == NULL) {
        temp = *root;
        *root = (*root)->right;
        free(temp);
        return 1;
    }else if ((*root)->right == NULL) {
        temp = *root;
        *root = (*root)->left;
        free(temp);
        return 1;
    }

    treeNode* parent = *root;
    treeNode* successor = (*root)->right;
    while (successor->left != NULL) {
        parent = successor;
        successor = successor->left;
    }

    (*root)->key = successor->key;
    if (parent != *root) {
        parent->left = successor->right;
    } else {
        parent->right = successor->right;
    }
    free(successor);
    return 1;

}

void printTree(treeNode* root){
    if (root == NULL) return;
    printf("%d ", root->key);
    printTree(root->left);
    printTree(root->right);
}