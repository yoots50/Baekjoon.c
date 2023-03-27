#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LINK {
	char data[21];
	int id;
	struct link* next;
}link;

typedef struct H_LINK {
	int len;
	link* f;
	link* l;
}h_link;

void initHLink(h_link* hl) {
	hl->len = 0;
	hl->f = hl->l = NULL;
}

void insertHLink(h_link* hl, char data[], int id) {
	link* newlink = (link*)malloc(sizeof(link));
	strcpy(newlink->data, data);
	newlink->next = NULL;
	newlink->id = id;

	if (hl->len) {
		hl->l->next = newlink;
	}

	else {
		hl->f = newlink;
	}

	hl->len++;
	hl->l = newlink;
}

int searchHLink(h_link* hl, char data[]) {
	link* ptr = hl->f;
	while (ptr != NULL) {
		if (!strcmp(ptr->data, data)) {
			return ptr->id;
		}
		ptr = ptr->next;
	}
	return -1;
}

int hash(char str[], int m) {
	int len = strlen(str);
	int ret = 0;
	for (int i = 0; i < len; i++) {
		ret += str[i];
	}
	
	return ret % m;
}

int strToInt(char str[]) {
	int len = strlen(str);
	int ret = 0;
	for (int i = 0; i < len; i++) {
		ret += str[i] - 48;
		ret *= 10;
	}

	return ret / 10;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	h_link* hl = (h_link*)malloc(sizeof(h_link) * 101);
	for (int i = 0; i < 101; i++) {
		initHLink(&hl[i]);
	}

	char** id = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		id[i] = (char*)malloc(sizeof(char) * 21);
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", id[i]);
		
		insertHLink(&hl[hash(id[i], 101)], id[i], i + 1);
	}

	char input[21];
	for (int i = 0; i < M; i++) {
		scanf("%s", input);
		if (65 <= input[0] && input[0] <= 90) {
			printf("%d\n", searchHLink(&hl[hash(input, 101)], input));
		}
		else {
			printf("%s\n", id[strToInt(input) - 1]);
		}
	}
}