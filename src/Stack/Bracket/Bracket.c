#include <stdio.h>
#include <string.h>

char stack[51];
int top=-1;

int is_empty(){
    return (top==-1);
}

void push(char element){
    if(top != -1 && top < 0)
        top++;
    stack[top++] = element;
}

void pop(){
    top--;
}

char *bracket_quest(char *arr){
    int len = strlen(arr);
    for(int i = 0; i < len; i++){
        if(arr[i] == '(')
            push(arr[i]);
        else if(arr[i] == ')'){
            if(is_empty())
                return "NO";
            pop();
        }
    }
    if(is_empty())
        return "YES";
    else
        return "NO";

}

int main(){
    char arr[51];
    int cnt;
    scanf("%d", &cnt);
    getchar();
    for(int i = 0; i < cnt; i++){
        scanf("%s", arr);
        printf("%s\n", bracket_quest(arr));
        top = -1;
    }
}