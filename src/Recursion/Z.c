#include <stdio.h>
#include <math.h>

int count = 0;
int x=0, y=0;

void Z_func(int N, int r, int c){
    if(N==2){
        if(abs(x-r)<2 && abs(y-c)<2){
            if(r==x&&c==y){
                printf("%d", count);
                return ;
            }
            count++;
            if (r==x&&(c+1)==y){
                printf("%d", count);
                return ;
            }
            count++;
            if ((r+1)==x&&c==y){
                printf("%d", count);
                return ;
            }
            count++;
            if ((r+1)==x&&(c+1)==y){
                printf("%d", count);
                return ;
            }
            return;
        } else{
            count += 4;
            return;
        }
    }

    Z_func(N/2, r, c);
    Z_func(N/2, r, c+N/2);
    Z_func(N/2, r+N/2, c);
    Z_func(N/2, r+N/2, c+N/2);
}

int main(){
    int N;
    scanf("%d %d %d", &N, &x, &y);

    Z_func(pow(2, N), 0, 0);
    return 0;
}