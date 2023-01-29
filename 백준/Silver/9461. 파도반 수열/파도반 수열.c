#include <stdio.h>

long long int memo[101] = { 0, };

long long int P(int N) {
	if (N <= 3) {
		return 1;
	}
	if (N <= 5) {
		return 2;
	}
	if (memo[N] != 0) {
		return memo[N];
	}
	memo[N] = P(N - 1) + P(N - 5);
	return memo[N];
}

int main() {
	int T;
	scanf("%d", &T);

	int N;
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%lld\n", P(N));
	}
}