#include <stdio.h>

int func(int N, int n) {
	if (N == n) {
		return 1;
	}
	if (N < n) {
		return 0;
	}
	return func(N, n + 1) + func(N, n + 2) + func(N, n + 3);
}

int main() {
	int T;
	scanf("%d", &T);
	int N;
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%d\n", func(N, 0));
	}
}