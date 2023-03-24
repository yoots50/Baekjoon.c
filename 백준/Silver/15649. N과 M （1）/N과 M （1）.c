#include <stdio.h>
#include <stdlib.h>

void arrPrint(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int func(int N, int M, int* v, int cnt, int* arr) {
	if (cnt == M) {
		arrPrint(arr, M);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!v[i]) {
			arr[cnt] = i + 1;
			v[i] = 1;
			func(N, M, v, cnt + 1, arr);
			v[i] = 0;
		}
	}
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int* v = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		v[i] = 0;
	}

	int* arr = (int*)malloc(sizeof(int) * M);
	func(N, M, v, 0, arr);
}