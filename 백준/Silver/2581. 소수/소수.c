#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	int* arr = (int*)malloc(sizeof(int) * (N + 1));

	for (int i = 2; i < N + 1; i++) {
		arr[i] = i;
	}

	int j, arrCpy;
	for (int i = 2; i < N + 1; i++) {
		if (arr[i] != 0) {
			j = i;
			arrCpy = arr[i];
			while (1) {
				j += arrCpy;
				if (j >= N + 1) {
					break;
				}
				arr[j] = 0;
			}
		}
	}

	if (M == 1) {
		M = 2;
	}

	int sum = 0;
	int min = 0;

	for (int i = M; i < N + 1; i++) {
		if (arr[i] != 0) {
			sum += arr[i];
			if (!min) {
				min = arr[i];
			}
		}
	}

	if (sum == 0) {
		printf("-1");
		return 0;
	}

	printf("%d\n%d", sum, min);
}
