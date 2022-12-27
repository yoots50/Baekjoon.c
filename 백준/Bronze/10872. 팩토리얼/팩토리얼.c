#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int answer = 1;
	for (int i = 0; i < N; i++) {
		answer *= (i + 1);
	}
	printf("%d", answer);
}