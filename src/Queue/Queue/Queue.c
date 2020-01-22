#include <stdio.h>
#include <string.h>

int queue[10000];
int front=-1, rear=-1, size=0;

int empty(){
    return front == rear;
}

void push(int element){
    queue[++rear] = element;
    size++;
}

int pop(){
    if(empty())
        return -1;
    size--;
    return queue[++front];
}

int front_t(){
    if(empty())
        return -1;
    return queue[front+1];
}

int back(){
    if(empty())
        return -1;
    return queue[rear];
}

int main(){
    int cnt, num;
    char command[6];
    scanf("%d", &cnt);
    getchar();
    for(int i = 0; i < cnt; i++){
        scanf("%s", command);
        if(!strcmp(command, "push")){
            scanf("%d", &num);
            push(num);
        }
        else if(!strcmp(command, "pop"))
            printf("%d\n", pop());
        else if (!strcmp(command, "size"))
            printf("%d\n", size);
        else if (!strcmp(command, "empty"))
            printf("%d\n", empty());
        else if(!strcmp(command, "front"))
            printf("%d\n", front_t());
        else
            printf("%d\n", back());
    }
}

