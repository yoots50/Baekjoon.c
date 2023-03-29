#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void removeEnter() {
	while (getchar() != '\n') {
	}
}

int func(int** graph, int N, int starti, int endi, int startj, int endj) {
	int cnt1 = 0, cnt0 = 0;

	for (int i = starti; i < endi; i++) {
		for (int j = startj; j < endj; j++) {
			if (graph[i][j]) {
				cnt1++;
			}
			else {
				cnt0++;
			}
		}
	}
	
	if (cnt1 == N * N) {
		printf("1");
	}

	else if (cnt0 == N * N) {
		printf("0");
	}

	else {
		printf("(");
		func(graph, N / 2, starti, endi - N / 2, startj, endj - N / 2);
		func(graph, N / 2, starti, endi - N / 2, startj + N / 2, endj);
		func(graph, N / 2, starti + N / 2, endi, startj, endj - N / 2);
		func(graph, N / 2, starti + N / 2, endi, startj + N / 2, endj);
		printf(")");
	}
}

int main() {
	int N;
	scanf("%d", &N);
	removeEnter();
	int** graph = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		graph[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++) {
			graph[i][j] = getchar() - '0';
		}
		removeEnter();
	}

	func(graph, N, 0, N, 0, N);
}