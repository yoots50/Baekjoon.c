#include <stdio.h>

int func(int i, int j, int N) {
	if (N == 3) {
		if (i == 2 && j == 2) {
			return 0;
		}
		return 1;
	}
	else if (N / 3 < i && i <= N * 2 / 3 && N / 3 < j && j <= N * 2 / 3) {
		return 0;
	}
	else {
		N /= 3;
		return func(i - N * (i / N), j - N * (j / N), N);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
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