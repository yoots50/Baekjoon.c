#include <stdio.h>

int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	int sum = 0;
	for (int i = A; i <= B; i++) {
		for (int k = 1; ; k++) {
			if (k * (k + 1) / 2 >= i) {
				sum += k;
				break;
			}
		}
	}
	printf("%d", sum);
}