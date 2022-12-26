#include <stdio.h>

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (temp < K) {
			printf("%d ", temp);
		}
	}
}