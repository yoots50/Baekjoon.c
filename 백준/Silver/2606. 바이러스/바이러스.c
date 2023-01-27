#include <stdio.h>
#include <stdlib.h>

int DFS(int** graph, int start, int N, int* visited) {
	int cnt = 0;
	visited[start] = 1;

	for (int i = 1; i < N; i++) {
		if (graph[start][i] == 1 && visited[i] == 0) {
			cnt += 1 + DFS(graph, i, N, visited);
		}
	}

	if (cnt == 0) {
		return 0;
	}

	return cnt;
}

int main() {
	int N, T;
	scanf("%d%d", &N, &T);

	N++;
	int** graph = (int**)malloc(sizeof(int*) * N);
	int x, y;

	for (int i = 0; i < N; i++) {
		graph[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++) {
			graph[i][j] = 0;
		}
	}

	for (int i = 0; i < T; i++) {
		scanf("%d%d", &x, &y);
		graph[y][x] = graph[x][y] = 1;
	}

	int* visited = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		visited[i] = 0;
	}

	printf("%d", DFS(graph, 1, N, visited));

}