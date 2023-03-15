#include <stdio.h>
#include <stdlib.h>

int func(int step, int start, int N, int M, int* arr, int prev) {
	if (step == M) {
		for (int i = 0; i < M; i++) {
			if (i != M - 1) {
				printf("%d ", arr[i]);
			}
			else {
				printf("%d\n", arr[i]);
			}
		}
		return 0;
	}

	for (int i = start; i < N; i++) {
		if (prev <= i) {
			arr[step] = i + 1;
			func(step + 1, i, N, M, arr, i);
		}
	}
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int* arr = (int*)malloc(sizeof(int) * M);
	func(0, 0, N, M, arr, 0);
}