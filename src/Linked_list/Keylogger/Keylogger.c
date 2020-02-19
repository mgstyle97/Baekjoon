#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct _DListNode{                      // 노드 구조체 선언
    element data;
    struct _DListNode *left, *right;
}DListNode;

DListNode *cursor = NULL;                       // 커서 포인터 변수

void init(DListNode *head)                      // 헤드 노드 초기화
{
    head->left = head->right = NULL;
    cursor = head;
}

void init_node(DListNode *node, element item)   // 노드 초기화
{
    node->right = node->left = NULL;
    node->data = item;
}

void insert(element item)                       // 삽입 연산
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    init_node(newnode, item);
    if(cursor->right == NULL){                  // 끝에 커서가 있는 경우 혹은 처음 노드를 삽입하는 경우
        newnode->left = cursor;
        cursor->right = newnode;
    }
    else{                                       // 중간에 노드를 삽입하는 경우 혹은 헤드와 노드 사이에 삽입하는 경우
        newnode->left = cursor;
        newnode->right = cursor->right;
        cursor->right->left = newnode;
        cursor->right = newnode;
    }
    cursor = newnode;                           // 커서 이동
}

void delete(DListNode *head)                    // 삭제 연산
{
    DListNode *removed = cursor;
    if(removed == head)                         // 커서가 헤드를 가리키고 있다면 삭제하지 않는다.
        return;
    if(cursor->right == NULL){                  // 커서가 끝에 노드를 가리키고 있는 경우
        removed->left->right = NULL;
    }
    else{                                       // 커서가 중간에 있는 경우
        removed->left->right = cursor->right;
        removed->right->left = cursor->left;
    }
    cursor = removed->left;                     // 커서 이동
    free(removed);
}

void move_cursor(char arrow)                    // 화살표를 통한 커서 이동
{
    switch (arrow){
        case '<':{
            if(cursor->left != NULL)            // 커서가 헤드 노드를 가리키고 있지 않는 경우
                cursor = cursor->left;
            break;
        }
        case '>':{
            if(cursor->right != NULL)           // 커서가 끝에 노드를 가리키고 있지 않는 경우
                cursor = cursor->right;
            break;
        }
    }
}

void print_list(DListNode *head)                // 리스트를 전체 출력한다.
{
    DListNode *p = head->right;
    while(p != NULL){
        printf("%c", p->data);
        p = p->right;
    }
    printf("\n");
}

void keylogger(char *str)                       // 키로거 함수
{
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));   // 헤드 노드 선언
    char ch;                                    // 문자열에 문자를 하나씩 저장할 변수
    unsigned int n = strlen(str);               // 문자열의 길이를 저장(없을 시 시간초과가 됨)

    init(head);                                 // 헤드 노드 초기화
    for(int i = 0; i < n; i++){
        ch = str[i];
        if(ch == '-')                           // 백스페이스의 경우
            delete(head);
        else if((ch == '>') || (ch == '<'))     // 화살표의 경우
            move_cursor(ch);
        else                                    // 단순 문자일 경우
            insert(ch);
    }
    print_list(head);                           // 문자열을 모두 출력
}

int main()
{
    char str[1000001] = {0};                    // 입력받을 문자열 배열 선언
    int n;

    scanf("%d", &n);                   // 몇번 입력받을 것인지

    for(int i = 0; i < n; i++){
        scanf("%s", str);               // 문자열 입력
        keylogger(str);
    }
}