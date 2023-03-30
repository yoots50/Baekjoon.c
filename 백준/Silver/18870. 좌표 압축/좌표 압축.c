#include <stdlib.h>

typedef struct DATA {
	int* ptr;
	int cord;
}data;

int compare(void* a, void* b) {
	int A = ((data*)a)->cord;
	int B = ((data*)b)->cord;

	if (A < B) {
		return -1;
	}
	return A > B;
}

int main() {
	int N;
	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * N);
	data* darr = (data*)malloc(sizeof(data) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &darr[i].cord);
	}

	for (int i = 0; i < N; i++) {
		darr[i].ptr = &arr[i];
	}

	qsort(darr, N, sizeof(darr[0]), compare);

	int prev = -1000001;
	int cnt = -1;
	for (int i = 0; i < N; i++) {
		if (darr[i].cord != prev) {
			*(darr[i].ptr) = ++cnt;
		}
		else {
			*(darr[i].ptr) = cnt;
		}
		prev = darr[i].cord;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
}