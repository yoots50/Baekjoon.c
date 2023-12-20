#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    
    int* sumArr = (int*)malloc(sizeof(int) * N);
    scanf("%d", &sumArr[0]);
    int input;
    for (int i = 1; i < N; i++) {
        scanf("%d", &input);
        sumArr[i] = sumArr[i - 1] + input;
    }
    
    int i, j;
    for (int k = 0; k < M; k++) {
        scanf("%d%d", &i, &j);
        printf("%d\n", sumArr[j - 1] - sumArr[i - 2]);
    }
}