#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	int idx = 0;
	int cnt = 0;
	int printed = 0;
	printf("<");
	while (printed < N) {
		while (idx <= N - 1) {
			if (arr[idx] != 0) {
				cnt++;
			}
			if (cnt == K) {
				if (printed == N - 1) {
					printf("%d", arr[idx]);
				}
				else {
					printf("%d, ", arr[idx]);
				}
				printed++;
				arr[idx] = 0;
				cnt = 0;
			}
			idx++;
			
		}
		idx = 0;
	}
	printf(">");
}