#include <stdio.h>
#include <stdlib.h>

int main() {
	int M, N;
	scanf("%d%d", &M, &N);
	int* arr = (int*)malloc(sizeof(int) * (N + 1));
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= N; i++) {
		if (arr[i]) {
			for (int j = 1; i + j * arr[i] <= N; j++) {
				arr[i + j * arr[i]] = 0;
			}
		}
	}
	if (M == 1) {
		M = 2;
	}
	for (int i = M; i <= N; i++) {
		if (arr[i]) {
			printf("%d\n", arr[i]);
		}
	}
}