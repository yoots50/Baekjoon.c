int func(int i, int j, int N) {
	if (N == 3) {
		if (j <= 3 - i) {
			return 0;
		}
		if (j >= 3 + i) {
			return 0;
		}
		if (i == 2 && j == 3) {
			return 0;
		}
		return 1;
	}
	if (j <= N - i) {
		return 0;
	}
	if (j >= N + i) {
		return 0;
	}
	if (i > N / 2) {
		if (i <= j && j <= N * 2 - i) {
			return 0;
		}
	}
	if (i <= N / 2) {
		return func(i, j - N / 2, N / 2);
	}
	else {
		if (j <= N) {
			return func(i - N / 2, j, N / 2);
		}
		else {
			return func(i - N / 2, j - N, N / 2);
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N * 2 - 1; j++) {
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