#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 101

typedef struct link{
	char data[21];
	struct link* next;
}l;

typedef struct hlink {
	l* f;
	l* l;
	int len;
}hl;

void inithl(hl* h) {
	h->len = 0;
	h->f = h->l = NULL;
}

void inserthl(hl* h, char data[]) {
	l* newl = (l*)malloc(sizeof(l));
	strcpy(newl->data, data);
	newl->next = NULL;

	if (h->len) {
		h->l->next = newl;
	}

	else {
		h->f = newl;
	}

	h->l = newl;
	h->len++;
}

int searchhl(hl* h, char data[]) {
	l* ptr = h->f;
	while (ptr != NULL) {
		if (!strcmp(ptr->data, data)) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

int hash(char data[]) {
	int len = strlen(data);
	int ret = 0;
	
	for (int i = 0; i < len; i++) {
		ret += data[i];
	}

	return ret % MOD;
}

int compare(void* a, void* b) {
	char* A = *(char**)a;
	char* B = *(char**)b;
	
	return strcmp(A, B);
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	hl* h = (hl*)malloc(sizeof(hl) * MOD);
	for (int i = 0; i < MOD; i++) {
		inithl(&h[i]);
	}

	char** namel = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		namel[i] = (char*)malloc(sizeof(char) * 21);
	}

	char input[21];
	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		inserthl(&h[hash(input)], input);
	}

	int idx = 0;
	for (int i = 0; i < M; i++) {
		scanf("%s", input);
		if (searchhl(&h[hash(input)], input)) {
			strcpy(namel[idx++], input);
		}
	}

	qsort(namel, idx, sizeof(namel[0]), compare);

	printf("%d\n", idx);
	for (int i = 0; i < idx; i++) {
		printf("%s\n", namel[i]);
	}
}