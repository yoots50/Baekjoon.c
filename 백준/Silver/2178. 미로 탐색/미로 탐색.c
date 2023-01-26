#include <stdio.h>
#include <stdlib.h>

typedef struct Points {
	int x;
	int y;
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

int BFS(const char** graph, const int i, const int j, const int col_len, const int row_len) {
	Queue queue;
	Points points = { 0, 0 };
	int** memo = (int**)malloc(sizeof(int*) * col_len);
	int** visited = (int**)malloc(sizeof(int*) * col_len);
	for (int i = 0; i < col_len; i++) {
		memo[i] = (int*)malloc(sizeof(int) * row_len);
		visited[i] = (int*)malloc(sizeof(int) * row_len);
		for (int j = 0; j < row_len; j++) {
			visited[i][j] = 0;
		}
	}
	int x;
	int y;
	initQueue(&queue);
	visited[i][j] = 1;
	points.x = i;
	points.y = j;
	enqueue(&queue, points);
	memo[i][j] = 1;
	while (queue.count) {
		points = dequeue(&queue);
		x = points.x;
		y = points.y;
		if (x == row_len - 1 && y == col_len - 1) {
			return memo[col_len - 1][row_len - 1];
		}
		if (x != row_len - 1 && visited[y][x + 1] == 0 && graph[y][x + 1] == '1') {
			visited[y][x + 1] = 1;
			memo[y][x + 1] = memo[y][x] + 1;
			points.x = x + 1;
			points.y = y;
			enqueue(&queue, points);
		}
		if (y != col_len - 1 && visited[y + 1][x] == 0 && graph[y + 1][x] == '1') {
			visited[y + 1][x] = 1;
			memo[y + 1][x] = memo[y][x] + 1;
			points.x = x;
			points.y = y + 1;
			enqueue(&queue, points);
		}
		if (x != 0 && visited[y][x - 1] == 0 && graph[y][x - 1] == '1') {
			visited[y][x - 1] = 1;
			memo[y][x - 1] = memo[y][x] + 1;
			points.x = x - 1;
			points.y = y;
			enqueue(&queue, points);
		}
		if (y != 0 && visited[y - 1][x] == 0 && graph[y - 1][x] == '1') {
			visited[y - 1][x] = 1;
			memo[y - 1][x] = memo[y][x] + 1;
			points.x = x;
			points.y = y - 1;
			enqueue(&queue, points);
		}
	}
	return 0;
}


int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	char** graph = (char**)malloc(sizeof(char*) * N);
	
	for (int i = 0; i < N; i++) {
		graph[i] = (char*)malloc(sizeof(char) * M);
		scanf("%s", graph[i]);
	}

	printf("%d", BFS(graph, 0, 0, N, M));
	
}