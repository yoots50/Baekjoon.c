#include <stdio.h>
#include <stdlib.h>

typedef struct Info {
    int weight;
    int value;
} info;

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main()
{
    int N, K, W, V;
    scanf("%d%d", &N, &K);
    
    info* things = (info*)malloc(sizeof(info) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &W, &V);
        things[i].weight = W;
        things[i].value = V;
    }
    
    int** dp = (int**)malloc(sizeof(int*) * (N + 1));
    for (int i = 0; i < N + 1; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (K + 1));
    }
    
    // dp[i][j]는 =가방이 최대로 버틸 수 있는 무게가 j일 때 i번째 물건까지 탐색했을 때의 최대 가치이다. https://velog.io/@jxlhe46/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%B0%B0%EB%82%AD-%EB%AC%B8%EC%A0%9C-Knapsack-Problem
    
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    
    for (int i = 0; i <= K; i++) {
        dp[0][i] = 0;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (things[i - 1].weight > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - things[i - 1].weight] + things[i - 1].value);
            }
        }
    }
    
    printf("%d", dp[N][K]);
}