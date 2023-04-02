#include <stdio.h>
#define MIN_HEAP_SIZE 100001

typedef struct {
	int arr[MIN_HEAP_SIZE];
	int size;
}mn_heap;

void init(mn_heap* mn) {
	mn->size = 0;
}

void insert(mn_heap* mn, int ins) {
	int idx = ++mn->size;
	
	while (idx != 1 && ins < mn->arr[idx / 2]) {
		mn->arr[idx] = mn->arr[idx / 2];
		idx /= 2;
	}

	mn->arr[idx] = ins;
}

int delete(mn_heap* mn) {
	if (mn->size == 0) {
		return -1;
	}

	int ret = mn->arr[1];
	int tmp = mn->arr[mn->size--];

	int parent = 1;
	int child = 2;

	while (child <= mn->size) {
		if (child < mn->size && mn->arr[child] > mn->arr[child + 1]) {
			child++;
		}

		if (tmp <= mn->arr[child]) {
			break;
		}

		mn->arr[parent] = mn->arr[child];
		parent = child;
		child *= 2;
	}

	mn->arr[parent] = tmp;
	return ret;
}

int main() {
	int N;
	scanf("%d", &N);

	mn_heap mn;
	init(&mn);

	int cmd;
	for (int i = 0; i < N; i++) {
		scanf("%d", &cmd);

		if (cmd) {
			insert(&mn, cmd);
		}

		else {
			if ((cmd = delete(&mn)) == -1) {
				printf("0\n");
			}

			else {
				printf("%d\n", cmd);
			}
		}
	}
	
}