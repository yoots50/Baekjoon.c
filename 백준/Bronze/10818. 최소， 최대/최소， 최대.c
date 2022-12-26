#include <stdio.h>

int main() {
	int N;
	int temp;
	int min, max;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (i == 0) {
			min = temp;
			max = temp;
		}
		else {
			if (min > temp) {
				min = temp;
			}
			if (max < temp) {
				max = temp;
			}
		}
	}
	printf("%d %d", min, max);
}