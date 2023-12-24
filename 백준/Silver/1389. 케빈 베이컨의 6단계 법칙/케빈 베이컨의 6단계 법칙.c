#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

typedef struct idxArray {
    int data;
    int idx;
} IDXARRAY;

int compare(const void* a, const void* b) {
    IDXARRAY A = *(IDXARRAY*)a;
    IDXARRAY B = *(IDXARRAY*)b;
    
    if (A.data < B.data) {
        return -1;
    }
    return A.data > B.data;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    
    int** graph = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        graph[i] = (int*)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = INF;
            }
        }    
    }
    
    int from, to;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &from, &to);
        graph[from - 1][to - 1] = 1;
        graph[to - 1][from - 1] = 1;
    }
    
    int ab, ak, kb;
    for (int k = 0; k < N; k++) {
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                ab = graph[a][b];
                ak = graph[a][k];
                kb = graph[k][b];
                graph[a][b] = ab > ak + kb ? ak + kb : ab;
            }
        }
    }
    
    IDXARRAY* arr = (IDXARRAY*)malloc(sizeof(IDXARRAY) * N);
    for (int i = 0; i < N; i++) {
        arr[i].data = 0;
        arr[i].idx = i;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i].data += graph[i][j];
        }
    }
    
    qsort(arr, N, sizeof(IDXARRAY), compare);
    
    printf("%d", arr[0].idx + 1);
}