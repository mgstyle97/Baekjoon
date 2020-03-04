#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int parent;
    int child;
}Node;

Node *tree = NULL;
int tree_size;

void delete_node(int remove)
{
    if(tree[remove].child == 0){
        tree[tree[remove].parent].child--;
        tree[remove].parent = tree_size;
        return;
    }
    for(int i = 0; i < tree_size-1; i++){
        if(tree[i].parent == remove){
            delete_node(i);
            tree[remove].child--;
        }
    }

    tree[remove].parent = tree_size;
}

int main()
{
    int n, parent, remove, cnt = 0;

    scanf("%d", &n);

    tree = (Node *)malloc((n + 1) * sizeof(Node));
    tree_size = n+1;

    for(int i = 0; i < n; i++)
        tree[i].child = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &parent);

        tree[i].parent = parent;
        tree[parent].child++;
    }

    scanf("%d", &remove);
    if(tree[remove].parent == -1){
        printf("%d\n", 0);
        return 0;
    }

    delete_node(remove);
    for(int i = 0; i < n; i++){
        if(tree[i].parent == tree_size)
            continue;
        if(tree[i].child == 0)
            cnt++;
    }
    printf("%d\n", cnt);
}