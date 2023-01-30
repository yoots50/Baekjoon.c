#include <stdio.h>

int main() {
	int realSum;
	scanf("%d", &realSum);

	int N;
	scanf("%d", &N);

	int price, amount;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &price, &amount);
		sum += price * amount;
	}

	if (sum == realSum) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}