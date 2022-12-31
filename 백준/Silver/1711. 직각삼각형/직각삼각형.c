#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	long long int** arr = (long long int**)malloc(sizeof(long long int*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (long long int*)malloc(sizeof(long long int) * 2);
		scanf("%lld%lld", &arr[i][0], &arr[i][1]);
	}
	int cnt = 0;
	long long int d1;
	long long int d2;
	long long int d3;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				d1 = (arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]);
				d2 = (arr[i][0] - arr[k][0]) * (arr[i][0] - arr[k][0]) + (arr[i][1] - arr[k][1]) * (arr[i][1] - arr[k][1]);
				d3 = (arr[k][0] - arr[j][0]) * (arr[k][0] - arr[j][0]) + (arr[k][1] - arr[j][1]) * (arr[k][1] - arr[j][1]);
				if (d1 == d2 + d3) {
					cnt++;
				}
				else if (d2 == d1 + d3) {
					cnt++;
				}
				else if (d3 == d1 + d2) {
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
}