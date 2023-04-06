#include <stdio.h>
#include <stdlib.h>

int arr[3] = { 0, };

int is_all_same(int** paper, int N, int starti, int startj) {
	int ret = paper[starti][startj];

	for (int i = starti; i < starti + N; i++) {
		for (int j = startj; j < startj + N; j++) {
			if (ret != paper[i][j]) {
				return -2;
			}
		}
	}

	return ret;
}

void func(int** paper, int nowN, int starti, int startj) {
	if (nowN == 1) {
		arr[paper[starti][startj] + 1]++;
		return;
	}

	int tmp = is_all_same(paper, nowN, starti, startj);
	if (tmp != -2) {
		arr[tmp + 1]++;
		return;
	}
	
	int N = nowN / 3;
	func(paper, N, starti, startj);
	func(paper, N, starti + N, startj);
	func(paper, N, starti + N * 2, startj);
	func(paper, N, starti, startj + N);
	func(paper, N, starti + N, startj + N);
	func(paper, N, starti + N * 2, startj + N);
	func(paper, N, starti, startj + N * 2);
	func(paper, N, starti + N, startj + N * 2);
	func(paper, N, starti + N * 2, startj + N * 2);
}

int main() {
	int N;
	scanf("%d", &N);

	int** paper = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		paper[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	func(paper, N, 0, 0);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", arr[i]);
	}
}