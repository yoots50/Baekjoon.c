#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);

	int A, B;

	for (int i = 1; i < T + 1; i++) {
		scanf("%d%d", &A, &B);
		printf("Case #%d: %d\n", i, A + B);
	}
}