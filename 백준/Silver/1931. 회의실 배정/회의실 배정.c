#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

int compare(void* a, void* b) {
	int* A = *(int**)a;
	int* B = *(int**)b;

	if (A[0] < B[0]) {
		return -1;
	}
	else if (A[0] > B[0]) {
		return 1;
	}
	else {
		if (A[1] < B[1]) {
			return -1;
		}
		return A[1] > B[1];
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int** schedule = (int**)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++) {
		schedule[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d%d", &schedule[i][0], &schedule[i][1]);
	}

	qsort(schedule, N, sizeof(schedule[0]), compare);

	int	startTime = INT_MAX;
	int cnt = 0;

	for (int i = N - 1; i >= 0; i--) {
		if (schedule[i][1] <= startTime) {
			startTime = schedule[i][0];
			cnt++;
		}
	}

	printf("%d", cnt);
}