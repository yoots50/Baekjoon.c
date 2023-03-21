#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long lld;

lld power(lld x, lld y, lld M, lld* memo) {
	if (y < 1) {
		return 1;
	}

	if (y == 1) {
		return x % M;
	}

	lld log2y = log2(y);
	lld pow2y = pow(2, log2y);

	if (memo[log2y - 1] != -1) {
		return ((memo[log2y - 1] % M) * (power(x, y - pow2y, M, memo) % M)) % M;
	}

	memo[log2y - 1] = ((power(x, pow2y / 2, M, memo) % M) * (power(x, pow2y / 2, M, memo) % M)) % M;
	return ((memo[log2y - 1] % M) * (power(x, y - pow2y, M, memo) % M)) % M;
}

lld revModuler(lld a, lld b, lld M) {
	lld log2m2 = log2(M - 2);
	lld* memo = (lld*)malloc(sizeof(lld) * log2m2);
	for (lld i = 0; i < log2m2; i++) {
		memo[i] = -1;
	}

	return ((a % M) * (power(b, M - 2, M, memo) % M)) % M;
}

lld mul(lld start, lld last, lld M) {
	lld ret = start;

	for (lld i = start + 1; i <= last; i++) {
		ret *= i;
		ret %= M;
	}

	return ret % M;
}

lld nCk(lld N, lld K, lld M) {
	return revModuler(mul(1, N, M), ((mul(1, K, M) % M) * (mul(1, N - K, M) % M)), M) % M;
}

int main() {
	lld N, K;
	scanf("%lld%lld", &N, &K);

	lld M = 1000000007;
	printf("%lld", nCk(N, K, M) % M);
}