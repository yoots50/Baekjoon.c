#include <stdio.h>
#include <stdlib.h>

long long int arrSUB(long long int* arr, long long int SUB, int length) {
	long long int sum = 0;
	long long int temp;
	for (int i = 0; i < length; i++) {
		if ((temp = arr[i] - SUB) > 0) {
			sum += temp;
		}
	}
	return sum;
}

int main() {
	int N;
	long long int M;
	scanf("%d%lld", &N, &M);
	long long int* arr = (long long int*)malloc(sizeof(long long int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	long long int end = 1000000000;
	long long int start = 0;
	long long int mid;
	while (end - start > 1) {
		mid = (end + start) / 2;
		if (arrSUB(arr, mid, N) < M) {
			end = mid;
		}
		else {
			start = mid;
		}
	}
	printf("%lld", start);
	return 0;
}