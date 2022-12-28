#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int sum = 1;
	for (int i = 0; ; i++) {
		if (N <= sum) {
			printf("%d", i + 1);
			break;
		}
		sum += 6 * (i + 1);
	}
}