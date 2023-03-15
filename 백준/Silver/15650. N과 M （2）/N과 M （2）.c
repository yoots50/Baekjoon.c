#include <stdio.h>
#include <stdlib.h>

int func(int step, int start, int* visited, int N, int M, int* arr) {
	if (step == M) {
		for (int i = 0; i < M; i++) {
			if (i != M - 1) {
				printf("%d ", arr[i]);
			}
			else {
				printf("%d\n", arr[i]);
			}
		}
		return 0;
	}

	for (int i = start; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			arr[step] = i + 1;
			func(step + 1, i + 1, visited, N, M, arr);
			visited[i] = 0;
		}
	}
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	
	int* visited = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		visited[i] = 0;
	}

	int* arr = (int*)malloc(sizeof(int) * M);
	func(0, 0, visited, N, M, arr);
}