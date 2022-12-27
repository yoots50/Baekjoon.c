#include <stdio.h>
#include <stdlib.h>
//#define NDEBUG

int arrmax(int* arr, int length) {
	int max;
	max = arr[0];
	for (int i = 1; i < length; i++) {
		if (max <= arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int arrmin(int* arr, int length) {
	int min;
	min = arr[0];
	for (int i = 1; i < length; i++) {
		min = min > arr[i] ? arr[i] : min;
	}
	return min;
}

int empty(int* arr, int length, int max) {
	int emptysum = 0;
	for (int i = 0; i < length; i++) {
		emptysum += max - arr[i];
	}
	return emptysum;
}

int isallsame(int* arr, int length) {
	for (int i = 0; i < length - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			return 0;
		}
	}
	return 1;
}


int main() {
	int N, M, B;
	scanf("%d%d%d", &N, &M, &B);
	int* arr = (int*)malloc(sizeof(int) * N * M);
	for (int i = 0; i < N * M; i++) {
		scanf("%d", &arr[i]);
	}
	long long int timesum = 0;
	int emptysum;
	int max;
	int min;
	int maxcnt = 0;
	while (1) {
		maxcnt = 0;
		max = arrmax(arr, N * M);
		emptysum = empty(arr, N * M, max);
		min = arrmin(arr, N * M);
#ifdef NDEBUG
		printf("max = %d, min = %d, emptysum = %d, B = %d\n", max, min, emptysum, B);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d ", arr[i * M + j]);
			}
			printf("\n");
		}
#endif
		if (isallsame(arr, N * M)) {
			printf("%lld %d", timesum, max);
			return 0;
		}
		for (int i = 0; i < N * M; i++) {
			if (arr[i] == max) {
				maxcnt++;
			}
		}
		if ((emptysum <= 2 * maxcnt + emptysum - N * M + maxcnt) && (emptysum <= B)) {
			timesum += emptysum;
			printf("%lld %d", timesum, max);
			return 0;
		}
		for (int i = 0; i < N * M; i++) {
			if (arr[i] == max) {
				arr[i]--;
				timesum += 2;
				B++;
			}
		}
	}
}