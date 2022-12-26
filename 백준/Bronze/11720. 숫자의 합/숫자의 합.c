#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int temp;
	int sum = 0;
	getchar();
	while ((temp = getchar()) != '\n') {
		sum += temp - 48;
	}
	printf("%d", sum);
}