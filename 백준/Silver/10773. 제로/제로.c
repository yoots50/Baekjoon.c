#include <stdio.h>
#include <stdlib.h>

int main() {
	int K;
	scanf("%d", &K);
	int* arr = (int*)malloc(sizeof(int) * K);
	int sum = 0;
	for (int i = 0; i < K; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < K; i++) {
		if (arr[i] == 0) {
			for (int j = i - 1; ; j--) {
				if (arr[j] != 0){
					sum -= arr[j];
					arr[j] = 0;
					break;
				}
			}
		}
		else {
			sum += arr[i];
		}
	}
	printf("%d", sum);
}