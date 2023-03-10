#include <stdio.h>

int main() {
	int A, B, N;
	scanf("%d%d%d", &A, &B, &N);

	int i = 0;
	while (i < N) {
		A %= B;
		A *= 10;
		i++; 
	}
	printf("%d\n", A / B);
}