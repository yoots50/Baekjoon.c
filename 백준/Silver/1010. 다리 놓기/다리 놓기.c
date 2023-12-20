#include <stdio.h>

int memo[30][30] = { { 0, }, };

int combination(n, r) {
    if (n == r) {
        return 1;
    }
    if (r == 0) {
        return 1;
    }
    if (r == 1) {
        return n;
    }
    if (memo[n][r] != 0) {
        return memo[n][r];
    }
    return memo[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() {
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		int n, r;
		scanf("%d%d", &r, &n);

		printf("%d\n", combination(n, r));
	}
}