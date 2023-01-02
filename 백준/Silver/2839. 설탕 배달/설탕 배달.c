#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	if (!(N % 5)) {
		printf("%d", N / 5);
	}
	else {
		int x = N / 5;
		while (x != 0) {
			for (int i = 1; i <= (N - 5 * x) / 3; i++) {
				if (x * 5 + i * 3 == N) {
					printf("%d", x + i);
					return 0;
				}
			}
			x--;
		}
		if (!(N % 3)) {
			printf("%d", N / 3);
			return 0;
		}
		printf("-1");
	}
}
