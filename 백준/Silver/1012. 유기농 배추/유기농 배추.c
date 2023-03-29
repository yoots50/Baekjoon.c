#include <stdio.h>
#include <stdlib.h>

typedef struct DATA {
	int i;
	int j;
}data;

typedef struct LINK {
	data d;
	struct LINK* next;
}link;

typedef struct QUEUE {
	link* f;
	link* l;
	int len;
}queue;

void initQueue(queue* q) {
	q->len = 0;
	q->f = q->l = NULL;
}

void enqueue(queue* q, data d) {
	link* newl = (link*)malloc(sizeof(link));
	newl->d = d;
	newl->next = NULL;

	if (q->len) {
		q->l->next = newl;
	}

	else {
		q->f = newl;
	}

	q->l = newl;
	q->len++;
}

data dequeue(queue* q) {
	link* ptr = q->f;
	data d;

	d = q->f->d;
	q->f = ptr->next;
	free(ptr);
	q->len--;

	return d;
}

int BFS(int** graph, int N, int M) {
	queue q;
	data now;

	initQueue(&q);


	int** v = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		v[i] = (int*)malloc(sizeof(int) * M);
		for (int j = 0; j < M; j++) {
			v[i][j] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!v[i][j] && graph[i][j]) {
				v[i][j] = 1;
				int nowi, nowj;
				data tmp = { i, j };
				enqueue(&q, tmp);
				while (q.len) {
					now = dequeue(&q);
					nowi = now.i;
					nowj = now.j;

					if (nowi + 1 < N && !v[nowi + 1][nowj] && graph[nowi + 1][nowj]) {
						tmp.i = nowi + 1;
						tmp.j = nowj;
						v[tmp.i][tmp.j] = 1;
						enqueue(&q, tmp);
					}

					if (nowi - 1 >= 0 && !v[nowi - 1][nowj] && graph[nowi - 1][nowj]) {
						tmp.i = nowi - 1;
						tmp.j = nowj;
						v[tmp.i][tmp.j] = 1;
						enqueue(&q, tmp);
					}

					if (nowj - 1 >= 0 && !v[nowi][nowj - 1] && graph[nowi][nowj - 1]) {
						tmp.i = nowi;
						tmp.j = nowj - 1;
						v[tmp.i][tmp.j] = 1;
						enqueue(&q, tmp);
					}

					if (nowj + 1 < M && !v[nowi][nowj + 1] && graph[nowi][nowj + 1]) {
						tmp.i = nowi;
						tmp.j = nowj + 1;
						v[tmp.i][tmp.j] = 1;
						enqueue(&q, tmp);
					}
				}
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	int T;
	scanf("%d", &T);

	int N, M, K;
	int x, y;
	for (int i = 0; i < T; i++) {
		scanf("%d%d%d", &N, &M, &K);
		int** graph = (int**)malloc(sizeof(int*) * N);
		for (int i = 0; i < N; i++) {
			graph[i] = (int*)malloc(sizeof(int) * M);
			for (int j = 0; j < M; j++) {
				graph[i][j] = 0;
			}
		}

		for (int j = 0; j < K; j++) {
			scanf("%d%d", &y, &x);
			graph[y][x] = 1;
		}

		printf("%d\n", BFS(graph, N, M));
	}
}