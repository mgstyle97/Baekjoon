#include <stdio.h>

int main(){

    int arr[10] = {0};
    int count=0;
    int num;

    for(int i = 0;i<10;i++){
        scanf_s("%d", &num);
        arr[i] = num % 42;
        count++;
    }

    for(int i = 0;i<10;i++){
        num = arr[i];
        if(num == 42)
            continue;
        for(int j = 0;j<10;j++){
            if(i != j && num == arr[j]){
                count--;
                arr[j] = 42;
            }
        }
    }

    printf("%d", count);
}

