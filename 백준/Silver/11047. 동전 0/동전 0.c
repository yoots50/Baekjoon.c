#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int cnt = 0;
	while (1) {
		if (K == 0) {
			break;
		}
		for (int i = N - 1; i >= 0; i--) {
			if (arr[i] <= K) {
				K -= arr[i];
				cnt++;
				break;
			}
		}
	}
	printf("%d", cnt);
}