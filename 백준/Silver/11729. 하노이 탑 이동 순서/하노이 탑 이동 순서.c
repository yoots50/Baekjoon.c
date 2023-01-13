#include <stdio.h>
#include <math.h>

void hanoi(int N, int from, int to, int aux) {
	if (N == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi(N - 1, from, aux, to);
	printf("%d %d\n", from, to);
	hanoi(N - 1, aux, to, from);
} 

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", (int)pow(2, N) - 1);
	hanoi(N, 1, 3, 2);
}