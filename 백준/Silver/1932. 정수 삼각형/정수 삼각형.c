#include <stdio.h>
#include <stdlib.h>

#define max(a,b)  (((a) > (b)) ? (a) : (b))

int func(int** arr, int** memo, int i, int j, int n) {
	if (i < 0) {
		return 0;
	}

	if (i == 0) {
		return arr[0][0];
	}

	if (j < 0 || j > i) {
		return 0;
	}

	if (memo[i][j] != -1) {
		return memo[i][j];
	}

	memo[i][j] = arr[i][j] + max(func(arr, memo, i - 1, j, n), func(arr, memo, i - 1, j - 1, n));
	return memo[i][j];
}

int main() {
	int n;
	scanf("%d", &n);

	int** arr = (int**)malloc(sizeof(int*) * n);
	int** memo = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (i + 1));
		memo[i] = (int*)malloc(sizeof(int) * (i + 1));
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &arr[i][j]);
			memo[i][j] = -1;
		}
	}
	
	int max = 0;
	int tmp;
	for (int i = 0; i < n; i++) {
		tmp = func(arr, memo, n - 1, i, n);
		if (tmp > max) {
			max = tmp;
		}
	}

	printf("%d", max);
}