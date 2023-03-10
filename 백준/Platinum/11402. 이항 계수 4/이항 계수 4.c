#include <stdio.h>
#include <stdlib.h>

typedef long long lld;

typedef struct LINK {
	int data;
	struct LINK* next;
}link;

typedef struct DEUQE {
	link* first;
	link* last;
}deque;

void initDeque(deque* d) {
	d->first = d->last = NULL;
}

void addFirst(deque* d, int data) {
	link* newlink = (link*)malloc(sizeof(link));
	newlink->data = data;
	newlink->next = NULL;

	if (d->first == NULL) {
		d->first = newlink;
	}
	else {
		d->last->next = newlink;
	}
	d->last = newlink;
}

deque Moduler(lld n, int m) {
	lld now = n;
	deque ret;
	deque* ptr = &ret;
	initDeque(ptr);
	while (now) {
		addFirst(ptr, now % m);
		now /= m;
	}
	return ret;
}

lld combination(int N, int K, int M, int** memo) {
	if (K == 0 || N == K) {
		return 1;
	}

	if (N < K) {
		return 0;
	}

	if (memo[N][K] != -1) {
		return memo[N][K];
	}

	memo[N][K] = (combination(N - 1, K - 1, M, memo) + combination(N - 1, K, M, memo)) % M;
	return memo[N][K];
}

int lucas(lld N, lld K, int M) {
	lld ret = 1;

	int** memo = (int**)malloc(sizeof(int*) * 2002);
	for (int i = 0; i < 2001; i++) {
		memo[i] = (int*)malloc(sizeof(int) * 2002);
		for (int j = 0; j < 2001; j++) {
			memo[i][j] = -1;
		}
	}

	deque Ndeque = Moduler(N, M);
	deque Kdeque = Moduler(K, M);
	link* nl = Ndeque.first;
	link* kl = Kdeque.first;
	int ndata, kdata;

	while (nl != NULL || kl != NULL) {
		if (nl != NULL) {
			ndata = nl->data;
			nl = nl->next;
		}
		else {
			ndata = 0;
		}
		if (kl != NULL) {
			kdata = kl->data;
			kl = kl->next;
		}
		else {
			kdata = 0;
		}
		ret *= combination(ndata, kdata, M, memo);
	}
	
	return ret % M;
}

int main() {
	lld N, K;
	int M;
	scanf("%lld%lld%d", &N, &K, &M);

	printf("%lld", lucas(N, K, M));
}