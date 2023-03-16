#include <stdio.h>
#include <stdlib.h>

typedef struct DATA {
	int i;
	int j;
}data;

int check(data* d, int len, int ri, int rj) {
	int i, j;

	for (int k = 0; k < len; k++) {
		i = d[k].i;
		j = d[k].j;

		if (rj == j || ri == i) {
			return 0;
		}

		if (abs(ri - i) == abs(rj - j)) {
			return 0;
		}
	}

	return 1;
}

int func(int N, int step, data* d) {
	int ret = 0;
	
	if (step == N) {
		return 1;
	}

	for (int j = 0; j < N; j++) {
		if (check(d, step, step, j)) {
			d[step].i = step;
			d[step].j = j;
			ret += func(N, step + 1, d);
		}
	}

	return ret;
}

int main() {
	int N;
	scanf("%d", &N);

	data* d = (data*)malloc(sizeof(data) * N);

	printf("%d", func(N, 0, d));
}