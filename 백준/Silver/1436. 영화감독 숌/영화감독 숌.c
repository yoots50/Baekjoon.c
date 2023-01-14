#include <stdio.h>
#include <math.h>

int func(int N) {
	int len = floor(log(N) + 1);
	int sixCnt = 0;
	for (int i = 0; i < len; i++) {
		if (N % 10 == 6) {
			sixCnt++;
		}
		else {
			sixCnt = 0;
		}
		if (sixCnt == 3) {
			return 1;
		}
		N /= 10;
	}
	return 0;
}

int main() {
	int N;
	scanf("%d", &N);
	int init = 666;
	int Ncnt = 1;
	while (1) {
		if (func(init)) {
			Ncnt++;
		}
		if (N == Ncnt - 1) {
			break;
		}
		init++;
	}
	printf("%d", init);
}