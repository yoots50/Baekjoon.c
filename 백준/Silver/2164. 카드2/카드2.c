#include <stdio.h>
#include <stdlib.h>

int func(int* arr, int length) {
	if (length == 1) {
		return arr[0];
	}
	else {
		int* arr1 = (int*)malloc(sizeof(int) * (length / 2));
		if (length % 2) {
			for (int i = 0; i < length / 2 - 1; i++) {
				arr1[i] = arr[(i + 1) * 2 + 1];
			}
			arr1[length / 2 - 1] = arr[1];
		}
		else {
			for (int i = 0; i < length / 2; i++) {
				arr1[i] = arr[i * 2 + 1];
			}
		}
		return func(arr1, length / 2);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	printf("%d", func(arr, N));
}