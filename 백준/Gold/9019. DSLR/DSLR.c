#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct data {
	char cmd[100];
}d;

typedef struct link {
	int d;
	struct link* next;
}l;

typedef struct queue {
	int len;
	l* f;
	l* l;
}q;

void initqueue(q* q) {
	q->len = 0;
	q->f = q->l = NULL;
}

void enqueue(q* q, int d) {
	l* newl = (l*)malloc(sizeof(l));
	newl->next = NULL;
	newl->d = d;

	if (q->len) {
		q->l->next = newl;
	}

	else {
		q->f = newl;
	}

	q->l = newl;
	q->len++;
}

int dequeue(q* q) {
	l* ptr = q->f;
	int ret = ptr->d;
	q->f = ptr->next;
	free(ptr);
	q->len--;
	return ret;
}

void delqueue(q* q) {
	l* tmp = q->f;
	l* tmp2;
	while (tmp != NULL) {
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

int D(int n) {
	return n * 2 % 10000;
}

int S(int n) {
	return n == 0 ? 9999 : n - 1;
}

int L(int n) {
	return n / 1000 + (n % 1000) * 10;
}

int R(int n) {
	return (n % 10) * 1000 + n / 10;
}

void BFS(int start, int result) {
	d* memo = (d*)malloc(sizeof(d) * 10000);
	int* visited = (int*)malloc(sizeof(int) * 10000);
	for (int i = 0; i < 10000; i++) {
		visited[i] = 0;
	}

	d tmp = { "" };
	memo[start] = tmp;

	q queue;
	q* ptr = &queue;

	initqueue(ptr);
	enqueue(ptr, start);

	int now;
	while (ptr->len) {
		now = dequeue(ptr);

		if (now == result) {
			free(visited);
			delqueue(ptr);
			printf("%s\n", memo[now].cmd);
			free(memo);
			return;
		}

		int Dn = D(now);
		int Sn = S(now);
		int Ln = L(now);
		int Rn = R(now);
		int len = strlen(memo[now].cmd);

		if (!visited[Dn]) {
			visited[Dn] = 1;
			memo[Dn] = memo[now];
			memo[Dn].cmd[len] = 'D';
			enqueue(ptr, Dn);
		}

		if (!visited[Sn]) {
			visited[Sn] = 1;
			memo[Sn] = memo[now];
			memo[Sn].cmd[len] = 'S';
			enqueue(ptr, Sn);
		}

		if (!visited[Ln]) {
			visited[Ln] = 1;
			memo[Ln] = memo[now];
			memo[Ln].cmd[len] = 'L';
			enqueue(ptr, Ln);
		}

		if (!visited[Rn]) {
			visited[Rn] = 1;
			memo[Rn] = memo[now];
			memo[Rn].cmd[len] = 'R';
			enqueue(ptr, Rn);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);

	int start, result;
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &start, &result);
		BFS(start, result);
	}
}