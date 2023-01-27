#include <stdio.h>
#include <stdlib.h>

typedef struct Points {
	int i;
	int j;
}Points;

typedef struct Node {
	Points data;
	struct Node* p;
}node;

typedef struct Queue {
	node* index_zero;
	node* index_last;
	int count;
}Queue;

void initQueue(Queue* queue) {
	queue->index_zero = queue->index_last = NULL;
	queue->count = 0;
}

void enqueue(Queue* queue, Points src) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = src;
	newNode->p = NULL;
	if (queue->count) {
		queue->index_last->p = newNode;
	}
	else {
		queue->index_zero = newNode;
	}
	queue->index_last = newNode;
	queue->count++;
}

Points dequeue(Queue* queue) {
	if (queue->count) {
		Points data;
		data = queue->index_zero->data;
		queue->index_zero = queue->index_zero->p;
		queue->count--;
		return data;
	}
	Points false = { -1, -1 };
	return false;
}

int BFS(int** graph, int N, int M) {
	int** visited = (int**)malloc(sizeof(int*) * N);
	int** memo = (int**)malloc(sizeof(int*) * N);
	int lastDay;
	int i, j;
	Queue queue;
	Queue* q = &queue;
	Points points;
	
	initQueue(q);

	for (int i = 0; i < N; i++) {
		visited[i] = (int*)malloc(sizeof(int) * M);
		memo[i] = (int*)malloc(sizeof(int) * M);
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] >= 1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				lastDay = memo[i][j] = 0;
				points.i = i;
				points.j = j;
				enqueue(q, points);
			}
		}
	}

	while (queue.count) {
		points = dequeue(q);
		i = points.i;
		j = points.j;

		if (i != N - 1 && visited[i + 1][j] == 0 && graph[i + 1][j] == 0) {
			graph[i + 1][j] = 1;
			lastDay = memo[i + 1][j] = memo[i][j] + 1;
			visited[i + 1][j] = 1;
			points.i = i + 1;
			points.j = j;
			enqueue(q, points);
		}
		if (i != 0 && visited[i - 1][j] == 0 && graph[i - 1][j] == 0) {
			graph[i - 1][j] = 1;
			lastDay =  memo[i - 1][j] = memo[i][j] + 1;
			visited[i - 1][j] = 1;
			points.i = i - 1;
			points.j = j;
			enqueue(q, points);
		}
		if (j != 0 && visited[i][j - 1] == 0 && graph[i][j - 1] == 0) {
			graph[i][j - 1] = 1;
			lastDay = memo[i][j - 1] = memo[i][j] + 1;
			visited[i][j - 1] = 1;
			points.i = i;
			points.j = j - 1;
			enqueue(q, points);
		}
		if (j != M - 1 && visited[i][j + 1] == 0 && graph[i][j + 1] == 0) {
			graph[i][j + 1] = 1;
			lastDay = memo[i][j + 1] = memo[i][j] + 1;
			visited[i][j + 1] = 1;
			points.i = i;
			points.j = j + 1;
			enqueue(q, points);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				return -1;
			}
		}
	}

	return lastDay;

}

int main() {
	int M, N;
	scanf("%d%d", &M, &N);
	int** graph = (int**)malloc(sizeof(int*) * N);
	
	for (int i = 0; i < N; i++) {
		graph[i] = (int*)malloc(sizeof(int) * M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	
	printf("%d", BFS(graph, N, M));

}