#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
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

void enqueue(Queue* queue, int src) {
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

int dequeue(Queue* queue) {
	if (queue->count) {
		int data;
		data = queue->index_zero->data;
		queue->index_zero = queue->index_zero->p;
		queue->count--;
		return data;
	}
	int false = -1;
	return false;
}

int compare(void* a, void* b) {
	int A = *(int*)a;
	int B = *(int*)b;

	if (A < B) {
		return -1;
	}
	return A > B;
}

int BFS(int* ladderFrom, int* ladderTo, int* snakeFrom, int* snakeTo, int N, int M) {
	Queue q;
	Queue* p = &q;
	int start = 1;
	int end;
	
	int* memo = (int*)malloc(sizeof(int) * 102);
	int* visited = (int*)malloc(sizeof(int) * 102);

	for (int i = 0; i < 102; i++) {
		visited[i] = 0;
	}

	initQueue(p);
	enqueue(p, start);
	memo[start] = 0;
	visited[start] = 1;

	int ans[10000];
	int ansidx = 0;
	
	while (q.count) {

		start = dequeue(p);

		for (int i = start + 1; i < start + 7; i++) {
			
			end = 0;

			if (i == 100) {
				ans[ansidx++] = memo[start] + 1;
				break;
			}

			for (int j = 0; j < N; j++) {
				if (ladderFrom[j] == i) {
					end = ladderTo[j];
					if (visited[end] == 0) {
						enqueue(p, end);
						visited[end] = 1;
						memo[end] = memo[start] + 1;
					}
				}
			}

			if (end == 0) {
				for (int j = 0; j < M; j++) {
					if (snakeFrom[j] == i) {
						end = snakeTo[j];
						if (visited[end] == 0) {
							enqueue(p, end);
							visited[end] = 1;
							memo[end] = memo[start] + 1;
						}
					}
				}
			}

			if (end == 0) {
				end = i;
				if (visited[end] == 0) {
					enqueue(p, end);
					visited[end] = 1;
					memo[end] = memo[start] + 1;
				}
			}
		}
	}

	free(memo);

	qsort(ans, ansidx, sizeof(ans[0]), compare);

	return ans[0];
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int* ladderFrom = (int*)malloc(sizeof(int) * N);
	int* ladderTo = (int*)malloc(sizeof(int) * N);
	int* snakeFrom = (int*)malloc(sizeof(int) * M);
	int* snakeTo = (int*)malloc(sizeof(int) * M);

	int from, to;

	for (int i = 0; i < N; i++) {
		scanf("%d%d", &from, &to);
		ladderFrom[i] = from;
		ladderTo[i] = to;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d%d", &from, &to);
		snakeFrom[i] = from;
		snakeTo[i] = to;
	}

	printf("%d", BFS(ladderFrom, ladderTo, snakeFrom, snakeTo, N, M));

	free(ladderFrom);
	free(ladderTo);
	free(snakeFrom);
	free(snakeTo);

	return 0;
}