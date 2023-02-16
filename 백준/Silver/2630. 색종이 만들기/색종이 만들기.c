#include <stdio.h>
#include <stdlib.h>

void func(int** arr, int* bp, int* wp, int len) {
	int bcnt = 0;
	int wcnt = 0;
	
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[i][j] == 1) {
				bcnt++;
			}
			else {
				wcnt++;
			}
		}
	}

	if (bcnt == len * len) {
		(*bp)++;
	}

	else if (wcnt == len * len) {
		(*wp)++;
	}

	else {
		int len2 = len / 2;
		int** cut = (int**)malloc(sizeof(int*) * len2);
		
		for (int i = 0; i < len2; i++) {
			cut[i] = (int*)malloc(sizeof(int) * len2);
		}

		for (int i = 0; i < len2; i++) {
			for (int j = 0; j < len2; j++) {
				cut[i][j] = arr[i][j];
			}
		}

		func(cut, bp, wp, len2);

		for (int i = 0; i < len2; i++) {
			for (int j = 0; j < len2; j++) {
				cut[i][j] = arr[i + len2][j];
			}
		}

		func(cut, bp, wp, len2);

		for (int i = 0; i < len2; i++) {
			for (int j = 0; j < len2; j++) {
				cut[i][j] = arr[i][j + len2];
			}
		}

		func(cut, bp, wp, len2);

		for (int i = 0; i < len2; i++) {
			for (int j = 0; j < len2; j++) {
				cut[i][j] = arr[i + len2][j + len2];
			}
		}

		func(cut, bp, wp, len2);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int** arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int b = 0, w = 0;
	int* bp = &b;
	int* wp = &w;

	func(arr, bp, wp, N);

	printf("%d\n%d", w, b);
}