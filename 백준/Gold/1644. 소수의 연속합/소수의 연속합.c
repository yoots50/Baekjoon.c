#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * (N + 1));
	int* primes = (int*)malloc(sizeof(int) * (N + 1));
	int primesLen = 0;


	for (int i = 2; i < N + 1; i++) {
		arr[i] = i;
	}
	
	for (int i = 2; i < N + 1; i++) {
		if (arr[i] != 0) {
			primes[primesLen++] = arr[i];
			int j = i;
			int aj = arr[i];

			while (1) {
				j += aj;
				if (j > N) {
					break;
				}
				arr[j] = 0;
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < primesLen; i++) {
		int sum = 0;
		for (int j = i; j < primesLen; j++) {
			sum += primes[j];
			if (sum == N) {
				cnt++;
			}
			if (sum > N) {
				break;
			}
		}
	}

	printf("%d", cnt);
}