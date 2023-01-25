#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int A = *(int*)a;
	int B = *(int*)b;
	if (A < B) {
		return -1;
	}
	return A > B;
}

int main() {
	int N;
	scanf("%d", &N);
	int* P = (int*)malloc(sizeof(int) * N);
	int Fsum = 0;
	int sub = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
		Fsum += P[i];
	}
	int sum = Fsum;
	qsort(P, N, sizeof(P[0]), compare);
	for (int i = N - 1; i >= 0; i--) {
		sub += P[i];
		sum += Fsum - sub;
	}
	printf("%d", sum);
}