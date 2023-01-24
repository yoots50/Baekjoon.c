#include <stdio.h>
#include <stdlib.h>

char func(int N, int i, int j) {
	int base;
	if (i < N) {
		if (j > N + i - 1) {
			return '.';
		} // right up
		if (j < N - (i + 1)) {
			return '.';
		} // left up
		if (j < N) {
			base = 'a' + N - i - (j - N) - 2;
		}
		else {
			base = 'a' + N - i + (j - N);
		}
	}
	if (i >= N) {
		if (i - N >= j) {
			return '.';
		} // left down
		if (2 * (N - 1) - (i - N) <= j) {
			return '.';
		} // right down
		if (j < N) {
			base = 'a' + i - N - (j - N);
		}
		else {
			base = 'a' + i - N + (j - N) + 2;
		}
	}
	while (base > 'z') {
		base -= 26;
	}
	return base;
}

int main() {
	int N, R1, C1, R2, C2;
	scanf("%d%d%d%d%d", &N, &R1, &C1, &R2, &C2);
	int calcN = 2 * N - 1;
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			printf("%c", func(N, i - (i / calcN) * calcN, j - (j / calcN) * calcN));
		}
		printf("\n");
	}
}