#include <stdio.h>

int main(){
    int score[5];
    int a, b, c, d;
    for(int i = 0; i<5;i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        score[i] = a+b+c+d;
    }
    int max = score[0], num = 1;
    for(int i = 0; i<5;i++){
        if(score[i] > max){
            max = score[i];
            num = i+1;
        }
    }
    printf("%d %d", num, max);
}
