#include <stdio.h>
#include <math.h>

int main() {
	int C;
	scanf("%d", &C);
	int N;
	int scores[1000];
	int sum = 0;
	int ave;
	int cnt = 0;
	for (int i = 0; i < C; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &scores[j]);
			sum += scores[j];
		}
		ave = (double)sum / N;
		for (int j = 0; j < N; j++) {
			if (ave < scores[j]) {
				cnt++;
			}
		}
		printf("%0.3f%%\n", round(((double)cnt * 100 / N) * 1000) / 1000);
		sum = 0;
		cnt = 0;
	}
}