#include <stdio.h>
#include <stdlib.h>
int N, M;

int checkCondition(int i, int* arr, int len) {
	for (int k = 0; k < len; k++) {
		if (arr[k] == i) {
			return 0;
		}
	}

	return 1;
}

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

int func(int step, int* arr, int* v, int* narr) {
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

	for (int i = 0; i < N; i++) {
		if (v[i] == 0 && checkCondition(narr[i], arr, step)) {
			arr[step] = narr[i];
			v[i] = 1;
			func(step + 1, arr, v, narr);
			v[i] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);

	int* narr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &narr[i]);
	}

	qsort(narr, N, sizeof(int), compare);

	int* v = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		v[i] = 0;
	}

	int* arr = (int*)malloc(sizeof(int) * M);
	func(0, arr, v, narr);
}