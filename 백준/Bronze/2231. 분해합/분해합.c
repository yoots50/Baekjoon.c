#include <stdio.h>
#include <math.h>

int main() {
	int N;
	scanf("%d", &N);
	int sum;
	int length;
	int temp;
	for (int i = 1; i < N; i++) {
		length = floor(log10(i) + 1);
		temp = i;
		sum = i;
		for (int j = 0; j < length; j++) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == N) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0");
}