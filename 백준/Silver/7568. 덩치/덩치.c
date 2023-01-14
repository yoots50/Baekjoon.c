#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int* A = *(int**)a;
	int* B = *(int**)b;
	if (A[0] < B[0] && A[1] < B[1]) {
		return 1;
	}
	return 0;
}

int main() {
	int N;
	scanf("%d", &N);
	int** arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 3);
		scanf("%d%d", &arr[i][0], &arr[i][1]);
		arr[i][2] = i;
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (compare(&arr[i], &arr[j])) {
				cnt++;
			}
		}
		printf("%d ", cnt + 1);
		cnt = 0;
	}
}