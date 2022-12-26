#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int sum = 0;
	int length = 0;
	int temp;
	int max;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (i == 0) {
			max = temp;
		}
		else {
			if (max < temp) {
				max = temp;
			}
		}
		sum += temp;
		length++;
	}
	printf("%f", (float)sum / max * 100 / length);
}