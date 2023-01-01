#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) {
		return 1;
	}
	else {
		if (*(int*)a < *(int*)b) {
			return -1;
		}
		else {
			return 0;
		}
	}
}

int binary_search(int* arr, int v, int length) {
	int start = 0;
	int end = length - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == v) {
			return 1;
		}
		else {
			if (arr[mid] < v) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
	}
	return 0;
}

int main() {
	int N;
	scanf("%d", &N);
	int* src = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &src[i]);
	}
	qsort(src, N, sizeof(int), compare);
	int M;
	scanf("%d", &M);
	int find;
	for (int i = 0; i < M; i++) {
		scanf("%d", &find);
		printf("%d\n", binary_search(src, find, N));
	}
}