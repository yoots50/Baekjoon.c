#include <stdio.h>

int isPrime(int n) {
	if (n == 1) {
		return 0;
	}
	for (int i = 2; i < n; i++) {
		if (!(n % i)) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int N;
	scanf("%d", &N);
	int cnt = 0;
	int scan;
	for (int i = 0; i < N; i++) {
		scanf("%d", &scan);
		if (isPrime(scan)) {
			cnt++;
		}
	}
	printf("%d", cnt);
}