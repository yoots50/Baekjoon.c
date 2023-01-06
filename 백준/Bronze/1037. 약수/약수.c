#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int input, min, max;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (!i) {
			min = input;
			max = input;
		}
		else {
			if (min > input) {
				min = input;
			}
			if (max < input) {
				max = input;
			}
		}
	}
	printf("%d", max * min);
}