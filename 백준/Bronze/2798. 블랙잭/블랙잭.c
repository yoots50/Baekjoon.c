#include <stdio.h>
#include <stdlib.h>
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int dmin;
	int sum;
	int min;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (i == 0 && j == 1 && k == 2) {;
					dmin = abs(M - sum);
					min = sum;
				}
				else if (dmin > abs(M - sum) && sum <= M) {
					dmin = abs(M - sum);
					min = sum;
				}
			}
		}
	}
	printf("%d", min);
}