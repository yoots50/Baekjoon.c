#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int* dp = (int*)malloc(sizeof(int) * N); // dp[i] => i번째 값을 마지막으로 하는 가장 긴 수열의 길이 출처: https://thingjin.tistory.com/entry/%EB%B0%B1%EC%A4%80-11053%EB%B2%88-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4-%ED%8C%8C%EC%9D%B4%EC%8D%AC
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
        }
    }
    
    printf("%d", ans);
}