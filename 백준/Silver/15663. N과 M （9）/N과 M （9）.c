#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

int N, M;

void func(int* arr, int s, int l, int step, int* stack) {
	if (step == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", stack[i]);
		}
		printf("\n");
		return;
	}

	for (int i = s; i <= l; i++) {
		if (arr[i]) {
			arr[i]--;
			stack[step] = i;
			func(arr, s, l, step + 1, stack);
			arr[i]++;
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);

	int* arr = (int*)malloc(sizeof(int) * MAX);
	for (int i = 0; i < MAX; i++) {
		arr[i] = 0;
	}

	int* stack = (int*)malloc(sizeof(int) * M);

	int tmp;
	int tmpmin = 10000;
	int tmpmax = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
		if (tmpmin > tmp) {
			tmpmin = tmp;
		}
		if (tmpmax < tmp) {
			tmpmax = tmp;
		}
	}

	func(arr, tmpmin, tmpmax, 0, stack);
}