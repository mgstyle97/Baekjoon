#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode{
    int data;
    struct _TreeNode *left, *right;
}TreeNode;

TreeNode* create(int item)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));

    node->data = item;
    node->left = node->right = NULL;

    return node;
}

TreeNode* insert_node(TreeNode *root, int key)
{
    if(root == NULL)
        return create(key);
    if(key < root->data)
        root->left = insert_node(root->left, key);
    else if(key > root->data)
        root->right = insert_node(root->right, key);

    return root;
}

void postorder(TreeNode *root)
{
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}

int main()
{
    TreeNode *root = NULL;
    int n;

    while(scanf("%d", &n) == 1){
        root = insert_node(root, n);
    }
    postorder(root);
}
