#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 26

typedef char element;
typedef struct _TreeNode{
    element data;
    struct _TreeNode *left, *right;
}TreeNode;

int top = -1;
TreeNode *stack[MAX_ELEMENT];

TreeNode* create(element ch)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = ch;
    node->right = node->left = NULL;
    return node;
}

void push(TreeNode *p)
{
    if(top < MAX_ELEMENT)
        stack[++top] = p;
}

TreeNode* pop()
{
    TreeNode *p = NULL;
    if(top >= 0)
        p = stack[top--];
    return p;
}

TreeNode* inorder_iter(TreeNode *root, element ch)
{
    while(1){
        for(;root; root = root->left)
            push(root);
        root = pop();
        if(!root)
            break;
        if(root->data == ch)
            return root;
        root = root->right;
    }

}

void preorder(TreeNode *root)
{
    if(root != NULL){
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root)
{
    if(root != NULL){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode *root)
{
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main()
{
    TreeNode *t = NULL;
    char str[6], null = '.';
    int n;

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        fgets(str, 6, stdin);
        TreeNode *node;
        if(t == NULL){
            node = create(str[0]);
            t = node;
        } else
            node = inorder_iter(t, str[0]);
        if(str[2] != null || str[4] != null){
            if(str[2] == null){
                TreeNode *node1 = create(str[4]);
                node->left = NULL;
                node->right = node1;
            }
            else if(str[4] == null){
                TreeNode *node1 = create(str[2]);
                node->left = node1;
                node->right = NULL;
            }
            else{
                TreeNode *node1 = create(str[2]);
                TreeNode *node2 = create(str[4]);
                node->left = node1;
                node->right = node2;
            }
        }
        getchar();
    }
    preorder(t);
    printf("\n");
    inorder(t);
    printf("\n");
    postorder(t);
}