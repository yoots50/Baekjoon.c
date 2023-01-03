#include <stdio.h>

int GCD(int a, int b) {
	if (!(a % b)) {
		return b;
	}
	return GCD(b, a % b);
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}

int main() {
	int T;
	scanf("%d", &T);
	int A, B;
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &A, &B);
		printf("%d\n", LCM(A, B));
	}
}