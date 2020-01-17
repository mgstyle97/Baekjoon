#include <stdio.h>
#include <stdlib.h>
int N, M, *c, result=0;

int main()
{

    scanf("%d %d", &N, &M);
    c = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", c+i);

    for(int i = 0; i < N-2; i++)
        for(int j = i+1; j < N-1; j++)
            for(int k = j+1; k < N; k++){
                if((c[i]+c[j]+c[k]) <= M && M-(c[i]+c[j]+c[k]) < M-result)
                    result = c[i]+c[j]+c[k];
            }
    printf("%d", result);
}