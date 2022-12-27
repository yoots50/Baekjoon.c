#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int v;
	scanf("%d", &v);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (v == arr[i]) {
			cnt++;
		}
	}
	printf("%d", cnt);
}