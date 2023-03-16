#include <stdio.h>
#include <stdlib.h>

int compare(void* a, void* b) {
	int A = *(int*)a;
	int B = *(int*)b;

	if (A > B) {
		return 1;
	}
	if (A < B) {
		return -1;
	}
	return 0;
}

void func(int* arr, int step, int N, int M, int* stack) {
	if (step == M) {
		for (int i = 0; i < M; i++) {
			if (i < M - 1) {
				printf("%d ", stack[i]);
			}
			else {
				printf("%d\n", stack[i]);
			}
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] >= stack[step - 1]) {
			stack[step] = arr[i];
			func(arr, step + 1, N, M, stack);
		}
	}

	return;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int* arr = (int*)malloc(sizeof(int) * N);
	int* stack = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(arr[0]), compare);
	func(arr, 0, N, M, stack);
}