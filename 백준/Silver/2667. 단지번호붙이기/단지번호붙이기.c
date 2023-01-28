#include <stdio.h>
#include <stdlib.h>

int compare(void* a, void* b) {
	int A = *(int*)a;
	int B = *(int*)b;

	if (A < B) {
		return -1;
	}
	return A > B;
}

int checkCondition(int i, int j, int N, char** graph, int** visited) {
	if (!(0 <= i && i < N)) {
		return 0;
	}
	if (!(0 <= j && j < N)) {
		return 0;
	}
	if (graph[i][j] == '0') {
		return 0;
	}
	if (visited[i][j] == 1) {
		return 0;
	}
	return 1;
}

int DFS(char** graph, int**visited, int i, int j, int N) {
	int cnt = 1;
	if (graph[i][j] == '0' || visited[i][j] == 1) {
		return 0;
	}
	visited[i][j] = 1;
	if (checkCondition(i + 1, j, N, graph, visited)) {
		cnt += DFS(graph, visited, i + 1, j, N);
	}
	if (checkCondition(i - 1, j, N, graph, visited)) {
		cnt += DFS(graph, visited, i - 1, j, N);
	}
	if (checkCondition(i, j + 1, N, graph, visited)) {
		cnt += DFS(graph, visited, i, j + 1, N);
	}
	if (checkCondition(i, j - 1, N, graph, visited)) {
		cnt += DFS(graph, visited, i, j - 1, N);
	}
	return cnt;
}

int main() {
	int N;
	scanf("%d", &N);

	char** graph = (char**)malloc(sizeof(char*) * N);

	for (int i = 0; i < N; i++) {
		graph[i] = (char*)malloc(sizeof(char) * N);
		scanf("%s", graph[i]);
	}

	int** visited = (int**)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++) {
		visited[i] = (int*)malloc(sizeof(int) * N);

		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}

	int temp;
	int idx = 0;
	int arr[500];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((temp = DFS(graph, visited, i, j, N)) != 0) {
				arr[idx++] = temp;
			}
		}
	}

	printf("%d\n", idx);

	qsort(arr, idx, sizeof(arr[0]), compare);

	for (int i = 0; i < idx; i++) {
		printf("%d\n", arr[i]);
	}

}