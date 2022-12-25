#include <stdio.h>
#include <stdlib.h>

int solution(int** arr, int length, int i, int j, int** memo) {
	int cnt = 0;

	if (i + 1 == length) {
		return arr[i][j];
	}
	else {
		if (memo[i][j] != 0) {
			return memo[i][j];
		}
		if (j == 0) {
			return arr[i][j] + solution(arr, length, i + 1, 1, memo) > arr[i][j] + solution(arr, length, i + 1, 2, memo) ? (memo[i][j] = arr[i][j] + solution(arr, length, i + 1, 2, memo)) : (memo[i][j] = arr[i][j] + solution(arr, length, i + 1, 1, memo));
		}
		else if (j == 1) {
			return arr[i][j] + solution(arr, length, i + 1, 0, memo) > arr[i][j] + solution(arr, length, i + 1, 2, memo) ? (memo[i][j] = arr[i][j] + solution(arr, length, i + 1, 2, memo)) : (memo[i][j] = arr[i][j] + solution(arr, length, i + 1, 0, memo));
		}
		else {
			return arr[i][j] + solution(arr, length, i + 1, 0, memo) > arr[i][j] + solution(arr, length, i + 1, 1, memo) ? (memo[i][j] = arr[i][j] + solution(arr, length, i + 1, 1, memo)) : (memo[i][j] = arr[i][j] + solution(arr, length, i + 1, 0, memo));
		}
	}
}

int main() {
	
	int N;
	scanf("%d", &N);
	int** arr = (int**)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++){
		arr[i] = (int*)malloc(sizeof(int) * 3);
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	int*** memo = (int**)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++) {
		memo[i] = (int*)malloc(sizeof(int) * 3);
		for (int j = 0; j < 3; j++) {
			memo[i][j] = 0;
		}
	}

	int min;
	min = solution(arr, N, 0, 0, memo);
	for (int i = 0; i < 2; i++) {
		if (min > solution(arr, N, 0, i + 1, memo)) {
			min = solution(arr, N, 0, i + 1, memo);
		}
	}
	printf("%d", min);
}