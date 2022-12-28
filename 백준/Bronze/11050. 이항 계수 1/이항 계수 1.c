#include <stdio.h>

int func(int N, int K) {
	if (K == 0 || K == N) {
		return 1;
	}
	return func(N - 1, K - 1) + func(N - 1, K);
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	printf("%d", func(N, K));
}