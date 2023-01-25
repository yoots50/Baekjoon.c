#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	int queue[10000];
	int append;
}q;

void init(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = 0;
	}
}

void arrShiftLeft(int* arr, int len) {
	for (int i = 1; i < len; i++) {
		arr[i - 1] = arr[i];
	}
	arr[len - 1] = 0;
}

int queue_pop(q* queue) {
	int pop;
	if (queue->append == 0) {
		return 0;
	}
	pop = queue->queue[0];
	arrShiftLeft(queue->queue, queue->append);
	queue->append--;
	return pop;
}

void queue_append(q* queue, int n) {
	queue->queue[queue->append] = n;
	queue->append++;
}

void DFS(const int** graph, int* visited, const int start, const int len) {
	visited[start] = 1;
	printf("%d ", start);
	for (int i = 1; i < len; i++) {
		if (graph[start][i] == 1 && visited[i] == 0) {
			DFS(graph, visited, i, len);
		}
	}
}

void BFS(const int** graph, int* visited, const int start, const int len) {
	q queue = { {0,},0 };
	q* queue_p = &queue;
	int pop;

	queue_append(queue_p, start);
	visited[start] = 1;

	while ((pop = queue_pop(queue_p)) != 0) {
		printf("%d ", pop);
		for (int i = 1; i < len; i++) {
			if (graph[pop][i] == 1 && visited[i] == 0) {
				queue_append(queue_p, i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	int N, M, V;
	scanf("%d%d%d", &N, &M, &V);
	N++;
	int** graph = (int**)malloc(sizeof(int*) * N);
	int* visited = (int*)malloc(sizeof(int) * N);
	init(visited, N);
	for (int i = 0; i < N; i++) {
		graph[i] = (int*)malloc(sizeof(int) * N);
		init(graph[i], N);
	}
	int x, y;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	DFS(graph, visited, V, N);
	printf("\n");
	init(visited, N);
	BFS(graph, visited, V, N);
}