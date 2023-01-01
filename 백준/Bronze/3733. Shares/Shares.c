#include <stdio.h>

int main() {
	int N, S;
	while (scanf("%d%d", &N, &S) != EOF) {
		printf("%d\n", (S / (N + 1)));
	}
}