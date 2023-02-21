#include <stdio.h>
#include <stdlib.h>

double calcSlope(int x1, int y1, int x2, int y2) {
	return (double)(y1 - y2) / (x1 - x2);
}

int main() {
	int N;
	scanf("%d", &N);
	int* buildings = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &buildings[i]);
	}
	int max = 0;

	for (int i = 0; i < N; i++) {
		double prevSlope = -10000000000;
		double slope;
		int cnt = 0;
		for (int j = i - 1; j >= 0; j--) {
			slope = calcSlope(j, buildings[i], i, buildings[j]);
			if (prevSlope < slope) {
				cnt++;
				prevSlope = slope;
			}
		}
		prevSlope = -10000000000;
		for (int j = i + 1; j < N; j++) {
			slope = calcSlope(j, buildings[j], i, buildings[i]);
			if (prevSlope < slope) {
				cnt++;
				prevSlope = slope;
			}
		}
		if (max < cnt) {
			max = cnt;
		}
	}
	printf("%d", max);
}
