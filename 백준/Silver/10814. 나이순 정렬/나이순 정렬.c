#include <stdio.h>
#include <stdlib.h>

typedef struct Values {
	int age;
	char name[201];
	int idx;
}values;

int compare(const void* a, const void* b) {
	values A = *(values*)a;
	values B = *(values*)b;
	if (A.age > B.age) {
		return 1;
	}
	else if (A.age < B.age) {
		return -1;
	}
	else {
		if (A.idx > B.idx) {
			return 1;
		}
		else if (A.idx < B.idx) {
			return -1;
		}
		else {
			return 0;
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	values* list;
	list = (values*)malloc(sizeof(values) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d%s", &list[i].age, list[i].name);
		list[i].idx = i;
	}
	qsort(list, N, sizeof(list[0]), compare);
	for (int i = 0; i < N; i++) {
		printf("%d %s\n", list[i].age, list[i].name);
	}
}