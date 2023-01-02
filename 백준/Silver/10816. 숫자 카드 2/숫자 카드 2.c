#include <stdio.h>

int arr[20000001] = { 0, };

int main() {
	int N;
	scanf("%d", &N);
	int scan;
	for (int i = 0; i < N; i++) {
		scanf("%d", &scan);
		arr[scan + 10000000]++;
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &scan);
		printf("%d ", arr[scan + 10000000]);
	}
}