#include <stdio.h>

int memo[1001] = { 0, };

int fibonacci(int N) {
	if (N == 1 || N == 2) {
		return 1;
	}
	if (memo[N] != 0) {
		return memo[N];
	}
	memo[N] = (fibonacci(N - 1) + fibonacci(N - 2)) % 10007;
	return memo[N];
}

int main() {
	int N;
	scanf("%d", &N);

	printf("%d\n", fibonacci(N + 1));
	
}