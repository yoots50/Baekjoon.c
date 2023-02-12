#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;

typedef struct Queue {
	node* first;
	node* last;
	int len;
}queue;

void initQueue(queue* q) {
	q->first = q->last = NULL;
	q->len = 0;
}

void Enqueue(queue* q, int data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if (q->len == 0) {
		q->first = newNode;
	}
	else {
		q->last->next = newNode;
	}

	q->last = newNode;
	q->len++;
}

int Dequeue(queue* q) {
	if (q->len == 0) {
		return -1;
	}

	node* p = q->first;
	int data = p->data;
	q->first = p->next;
	free(p);
	q->len--;

	return data;
}

int BFS(int start, int end) {
	queue q;
	queue* p = &q;
	initQueue(p);

	if (start == end) {
		return 0;
	}

	int tmp;

	if (start > end) {
		return start - end;
	}

	char* visited = (char*)malloc(sizeof(char) * end * 2);
	for (int i = 0; i < end * 2; i++) {
		visited[i] = 0;
	}

	short* mov = (short*)malloc(sizeof(short) * end * 2);

	visited[start] = 1;
	mov[start] = 0;
	Enqueue(p, start);

	int data;

	while ((data = Dequeue(p)) != -1) {
		if (data == end) {
			break;
		}
		if (data < end && visited[data * 2] == 0) {
			visited[data * 2] = 1;
			mov[data * 2] = mov[data] + 1;
			Enqueue(p, data * 2);
		}
		if (data < end && visited[data + 1] == 0) {
			visited[data + 1] = 1;
			mov[data + 1] = mov[data] + 1;
			Enqueue(p, data + 1);
		}
		if (data > 0 && visited[data - 1] == 0) {
			visited[data - 1] = 1;
			mov[data - 1] = mov[data] + 1;
			Enqueue(p, data - 1);
		}
	}

	return mov[end];
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	printf("%d", BFS(N, K));
}