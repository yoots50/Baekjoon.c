#include <stdio.h>

typedef struct values{
	int zeros;
	int ones;
}v;

v memo[41] = { {0, 0}, };

v fibonacci(int n) {
	v values = {0, 0};
	if (n == 0) {
		values.zeros++;
		return values;
	}
	if (n == 1) {
		values.ones++;
		return values;
	}
	if (memo[n].zeros!= 0 && memo[n].ones != 0) {
		return memo[n];
	}
	else {
		memo[n].zeros = fibonacci(n - 1).zeros + fibonacci(n - 2).zeros;
		memo[n].ones = fibonacci(n - 1).ones + fibonacci(n - 2).ones;
		return memo[n];
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int n;
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		v values = fibonacci(n);
		printf("%d %d\n", values.zeros, values.ones);
	}
}