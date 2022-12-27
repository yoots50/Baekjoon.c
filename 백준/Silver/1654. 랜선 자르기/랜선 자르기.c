#include <stdio.h>
#include <stdlib.h>
int main() {
	int K, N;
	scanf("%d%d", &K, &N);
	int* arr = (int*)malloc(sizeof(int) * K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &arr[i]);
	}
	long long int max;
	max = arr[0];
	for (int i = 1; i < K; i++) {
		max = max < arr[i] ? arr[i] : max;
	}
	long long int start = 1;
	long long int end = max;
	long long int mid;
	long long int sum1 = 0;
	long long int sum2 = 0;
	long long int temp = 0;
	while (1) {
		mid = (start + end) / 2;
		if (temp == mid) {
			printf("%lld", max);
			return 0;
		}
		for (int i = 0; i < K; i++) {
			sum1 += arr[i] / mid;
			sum2 += arr[i] / (mid + 1);
		}
		if (sum1 >= N && sum2 < N) {
			printf("%lld", mid);
			return 0;
		}
		else {
			temp = mid;
			if (sum1 < N) {
				end = mid;
			}
			else if (sum2 >= N) {
				start = mid;
			}
		}
		sum1 = 0;
		sum2 = 0;
	}
}