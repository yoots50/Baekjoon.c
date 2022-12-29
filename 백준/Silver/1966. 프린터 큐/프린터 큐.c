#include <stdio.h>
#include <stdlib.h>

int arrShiftLeft(int* arr, int length) {
	int temp = arr[0];
	for (int i = 1; i < length; i++) {
		arr[i - 1] = arr[i];
	}
	arr[length - 1] = temp;
}

int arrMax(int* arr, int length) {
	int max = arr[0];
	for (int i = 0; i < length; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int main() {
	int T;
	scanf("%d", &T);
	int N, M;
	int cnt = 1;
	int max;
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &N, &M);
		int* arr = (int*)malloc(sizeof(int) * N);
		int* idx = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
			idx[j] = j;
		}
		while (1) {
			max = arrMax(arr, N);
			if (idx[0] == M && arr[0] == max) {
				printf("%d\n", cnt);
				cnt = 1;
				break;
			}
			else if (arr[0] < max) {
				arrShiftLeft(arr, N);
				arrShiftLeft(idx, N);
			}
			else if (arr[0] == max) {
				arr[0] = 0;
				cnt++;
			}
		}
	}
}