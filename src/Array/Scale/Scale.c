#include <stdio.h>
int main(){
    int a[8]={0};
    int cnt=0;
    for(int i = 0; i<8;i++){
        scanf("%d", a+i);
    }
    for(int i = 0; i<7;i++){
        if(a[i]-a[i+1]==1)
            cnt--;
        else if(a[i]-a[i+1] == -1)
            cnt++;
    }
    if(cnt == 7)
        printf("ascending");
    else if(cnt == -7)
        printf("descending");
    else
        printf("mixed");
}
