#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check(int now, int* banned) {
	if (now == 0 && banned[0]) {
		return 0;
	}

	while (now > 0) {
		if (banned[now % 10]) {
			return 0;
		}
		now /= 10;
	}

	return 1;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int idx;
	int banned[10] = { 0, };

	for (int i = 0; i < M; i++) {
		scanf("%d", &idx);
		banned[idx] = 1;
	}

	int ans = N > 100 ? N - 100 : 100 - N;
	int pressed;
	for (int i = 0; i <= 1000000; i++) {
		if (check(i, banned)) {
			pressed = N > i ? N - i : i - N;
			pressed += i ? floor(log10(i) + 1) : 1;

			if (pressed < ans) {
				ans = pressed;
			}
		}
	}

	printf("%d", ans);
}