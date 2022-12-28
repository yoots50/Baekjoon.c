#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int cntng[10001] = { 0 };
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		cntng[temp]++;
	}
	for (int i = 0; i < 10001; i++) {
		if (cntng[i] != 0) {
			for (int j = 0; j < cntng[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
}