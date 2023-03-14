#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long lld;

lld power(lld x, lld y, lld m, lld* memo) {
	if (y < 1) {
		return 1;
	}
	if (y == 1) {
		return x % m;
	}
	lld log2y = log2(y);
	lld powlog = pow(2, log2y);
	if (memo[log2y - 1] != -1) {
		return ((memo[log2y - 1] % m) * (power(x, y - powlog, m, memo) % m)) % m;
	}
	memo[log2y - 1] = ((power(x, powlog / 2, m, memo) % m) * (power(x, powlog / 2, m, memo) % m)) % m;
	return ((memo[log2y - 1] % m) * (power(x, y - powlog, m, memo) % m)) % m;
}

int modulo(int Si, int Ni, int m, int M) {
	int Q;
	int log2m2 = log2(m - 2);
	lld* memo = (lld*)malloc(sizeof(lld) * log2m2);
	for (int i = 0; i < log2m2; i++) {
		memo[i] = -1;
	}
	Q = ((Si % m) * (power(Ni, m - 2, m, memo) % m)) % m;
	return Q;
}

int main() {
	int M;
	scanf("%d", &M);
	
	int Ni, Si;
	int m = 1000000007;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &Ni, &Si);
		ans += modulo(Si, Ni, m, M);
		ans %= m;
	}
	printf("%d", ans);
}