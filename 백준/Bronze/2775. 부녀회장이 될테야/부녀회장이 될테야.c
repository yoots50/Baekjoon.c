#include <stdio.h>

int func(int k, int n) {
	if (k == 0) {
		return n;
	}
	else {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += func(k - 1, i);
		}
		return sum;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int k, n;
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &k, &n);
		printf("%d\n", func(k, n));
	}
}