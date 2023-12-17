#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    
    int** arr = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(sizeof(int) * N);
        int input;
        for (int j = 0; j < N; j++) {
            scanf("%d", &input);
            if (j == 0) {
                arr[i][j] = input;
            }
            arr[i][j] = arr[i][j - 1] + input;
        }
    }
    
    int x1, y1, x2, y2;
    int sum;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        sum = 0;
        for (int x = x1 - 1; x < x2; x++) {
            sum += arr[x][y2 - 1] - arr[x][y1 - 2];
        }
        printf("%d\n", sum);
    }
}
