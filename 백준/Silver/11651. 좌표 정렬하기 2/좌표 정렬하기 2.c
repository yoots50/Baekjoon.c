#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int* arr1 = *(int**)a;
	int* arr2 = *(int**)b;
	if (arr1[1] > arr2[1]) {
		return 1;
	}
	else {
		if (arr1[1] < arr2[1]) {
			return -1;
		}
		else {
			if (arr1[0] > arr2[0]) {
				return 1;
			}
			else {
				if (arr1[0] < arr2[0]) {
					return -1;
				}
				return 0;
			}
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int** arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d%d", &arr[i][0], &arr[i][1]);
	}
	qsort(arr, N, sizeof(arr[0]), compare);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", arr[i][0], arr[i][1]);
	}
}