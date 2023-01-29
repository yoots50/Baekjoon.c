#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int func(int* points, int now, int prev, int** memo) {
	if (now == 1) {
		return points[0];
	}

	if (now == 2) {
		if (prev - now == 1) {
			return points[1];
		}
		return points[0] + points[1];
	}

	if (memo[now][prev] != 0) {
		return memo[now][prev];
	}
	
	if (prev - now == 1) {
		memo[now][prev] = points[now - 1] + func(points, now - 2, now, memo);
		return memo[now][prev];
	}

	memo[now][prev] = points[now - 1] + MAX(func(points, now - 1, now, memo), func(points, now - 2, now, memo));
	return memo[now][prev];
}

int main() {
	int N;
	scanf("%d", &N);

	int* points = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &points[i]);
	}

	int** memo = (int**)malloc(sizeof(int*) * 302);

	for (int i = 0; i < 302; i++) {
		memo[i] = (int*)malloc(sizeof(int) * 302);
		for (int j = 0; j < 302; j++) {
			memo[i][j] = 0;
		}
	}

	printf("%d", func(points, N, N, memo));

	free(points);

	return 0;
}