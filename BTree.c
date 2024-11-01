#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    void* data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct Tree{
    struct TreeNode* Root;
};
struct TreeNode* setUpNode(void* data){
struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
return node;
}
struct Tree* settingUpTree(void* data) {
    struct Tree* tree = malloc(sizeof(struct Tree));
    tree->Root= setUpNode(data);
    return tree;
}

void insertNode(struct Tree* tree, struct TreeNode* newNode, int (*cmp)(void*,void*)) {
    if (tree->Root != NULL) {
        struct TreeNode* current = tree->Root;
        struct TreeNode* parent = NULL;
        while (current != NULL) {
            parent = current;
            if (cmp(newNode->data,current->data) < 0) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (cmp(newNode->data, parent->data) < 0) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    } else {
        tree->Root = newNode;
    }
}

struct TreeNode* findMin(struct TreeNode* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct TreeNode* deleteNode(struct TreeNode* root, void* data, int (*cmp)(void*, void*)) {
    if (root == NULL) return root;
    if (cmp(data, root->data) < 0) {
        root->left = deleteNode(root->left, data, cmp);
    } else if (cmp(data, root->data) > 0) {
        root->right = deleteNode(root->right, data, cmp);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, cmp);
    }
    return root;
}

void printPreOrder(struct TreeNode* node){
    if (node == NULL) {
        return;
    }
    printf("%d\n", *(int*) node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printFullTree(struct TreeNode* node, int space, int level) {
    if (node == NULL) {
        return;
    }
    int spacing = 6;
    space += spacing;
    printFullTree(node->right, space, level + 1);
    printf("\n");
    for (int i = spacing; i < space; i++) {
        printf(" ");
    }
    if (level > 0) {
        printf("|-- ");
    }
    printf("%d\n", *(int*)node->data);
    printFullTree(node->left, space, level + 1);
}

int cmp(void* a, void* b) {
    int intA = *(int*)a;
    int intB = *(int*)b;
    if (intA < intB) return -1;
    if (intA > intB) return 1;
    return 0;
}
void flipTree(struct TreeNode* root) {
    if (root == NULL) return;
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    flipTree(root->right);
    flipTree(root->left);

}

void freeTree(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// int main() {
//     int data1 = 10;
//     int data2 = 5;
//     int data3 = 20;
//     int data4 = 3;
//     int data5 = 7;
//     int data6 = 15;
//
//     struct Tree* tree = settingUpTree(&data1);
//     insertNode(tree, setUpNode(&data2), cmp); // Insert 5
//     insertNode(tree, setUpNode(&data3), cmp); // Insert 20
//     insertNode(tree, setUpNode(&data4), cmp); // Insert 3
//     insertNode(tree, setUpNode(&data5), cmp); // Insert 7
//     insertNode(tree, setUpNode(&data6), cmp); // Insert 15
//
//     printf("Pre-order traversal of the tree:\n");
//     printPreOrder(tree->Root);
//     printf("\n");
//
//     printf("Full tree structure before:\n");
//     printFullTree(tree->Root, 0, 0);
//
//     // tree->Root = deleteNode(tree->Root, &data5, cmp); // Delete 7
// printf("---------\n");
//     printf("Tree flipped");
//     // printf("\nTree structure after deleting 7:\n");
//     // printFullTree(tree->Root, 0, 0);
//     flipTree(tree->Root);
//     printFullTree(tree->Root,0,0);
//     freeTree(tree->Root);
//     free(tree);
//
//
//     return 0;
// }
