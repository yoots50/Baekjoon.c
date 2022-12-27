#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int* arr = (int*)malloc(sizeof(int) * N * M * 2);
	for (int i = 0; i < N * M * 2; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", arr[i * M + j] + arr[i * M + j + N * M]);
		}
		printf("\n");
	}
}