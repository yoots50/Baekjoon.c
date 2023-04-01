#include <stdio.h>
#define MAX_HEAP_SIZE 200000

typedef struct MAX_HEAP {
	int arr[MAX_HEAP_SIZE];
	int size;
}mx_heap;

void init_max_heap(mx_heap* mx) {
	mx->size = 0;
}

void insert_max_heap(mx_heap* mx, int data) {
	int idx;
	idx = ++(mx->size);

	while (idx != 1 && data > mx->arr[idx / 2]) {
		mx->arr[idx] = mx->arr[idx / 2];
		idx /= 2;
	}

	mx->arr[idx] = data;
}

int remove_max_heap(mx_heap* mx) {
	if (mx->size == 0) {
		return -1;
	}

	int parent, child;
	int ret, tmp;

	ret = mx->arr[1];
	tmp = mx->arr[mx->size--];

	parent = 1;
	child = 2;

	while (child <= mx->size) {
		if (child < mx->size && (mx->arr[child] < mx->arr[child + 1])) {
			child++;
		}

		if (tmp >= mx->arr[child]) {
			break;
		}

		mx->arr[parent] = mx->arr[child];
		parent = child;
		child *= 2;
	}

	mx->arr[parent] = tmp;
	return ret;
}

int main() {
	int N;
	scanf("%d", &N);

	mx_heap mx;
	init_max_heap(&mx);

	int cmd;
	int e;
	for (int i = 0; i < N; i++) {
		scanf("%d", &cmd);
		if (cmd) {
			insert_max_heap(&mx, cmd);
		}

		else {
			if ((e = remove_max_heap(&mx)) == -1) {
				printf("0\n");
			}

			else {
				printf("%d\n", e);
			}
		}
	}
}