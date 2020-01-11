#include <stdio.h>
#include <stdlib.h>
int MIN, NUM;
int S[10], D[10];

void Search(int depth, int n, int a, int b){
    if(depth == n){
        int temp = abs(a-b);
        if(temp < MIN)
            MIN = temp;
        return;
    }
    for(int i = depth +1;i<NUM;i++){
        Search(i, n, a*S[i], b+D[i]);
    }
    return;
}

int main(void) {
    MIN = 987654321;
    scanf("%d", &NUM);
    for(int i = 0;i<NUM;i++){
        scanf("%d %d", &S[i], &D[i]);
    }
    for(int i = 0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            Search(j, i, S[j], D[j]);
        }
    }
    printf("%d\n", MIN);
    return 0;
}