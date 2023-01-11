#include <stdio.h>
#include <math.h>

int func(int i, int j, int N) {
	int realN = log2(N + 1);
	if (N == 1) {
		return 1;
	}
	else {
		if (realN % 2) {
			if (i == N) {
				return 1;
			}
			if (j == N - i + 1 || j == N + i - 1) {
				return 1;
			}
			if (i >= (N + 1) / 2 && i + 1 <= j && j <= 2 * N - 1 - i) {
				return func(i + 1 - (N + 1) / 2, j - (N + 1) / 2, pow(2, realN - 1) - 1);
			}
			return 0;
		}
		else {
			if (i == 1) {
				return 1;
			}
			if (i == j || i == (2 * N - j)) {
				return 1;
			}
			if (i <= (N + 1) / 2 && N - (i - 2) <= j && j <= N + (i - 2)) {
				return func(i - 1, j - (N + 1) / 2, pow(2, realN - 1) - 1);
			}
			return 0;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	if (N % 2) {
		N = pow(2, N) - 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N + i - 1 ; j++) {
				if (func(i, j, N)) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	else {
		N = pow(2, N) - 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 2 * N - i; j++) {
				if (func(i, j, N)) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
}