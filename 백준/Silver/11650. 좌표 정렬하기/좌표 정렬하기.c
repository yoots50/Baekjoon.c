#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int* coordinates1 = *(int**)a;
	int* coordinates2 = *(int**)b;
	if (coordinates1[0] > coordinates2[0]) {
		return 1;
	}
	else if (coordinates1[0] < coordinates2[0]) {
		return -1;
	}
	else {
		if (coordinates1[1] > coordinates2[1]) {
			return 1;
		}
		else if (coordinates1[1] < coordinates2[1]) {
			return -1;
		}
		else {
			return 0;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int** coordinates = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		coordinates[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d%d", &coordinates[i][0], &coordinates[i][1]);
	}
	qsort(coordinates, N, sizeof(coordinates[0]), compare);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", coordinates[i][0], coordinates[i][1]);
	}
}