#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

int d(int n) {
	int sum = n;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int* arr = (int*)malloc(sizeof(int) * MAX);
	int* answer = (int*)malloc(sizeof(int) * MAX);
	for (int i = 1; i < MAX; i++) {
		arr[i] = i;
	}
	for (int i = 1; i < MAX; i++) {
		answer[i] = 1;
	}
	
	int dn;
	for (int i = 1; i < MAX; i++) {
		dn = d(arr[i]);
		if (dn < MAX) {
			answer[dn] = 0;
		}
	}

	for (int i = 1; i < MAX; i++) {
		if (answer[i]) {
			printf("%d\n", i);
		}
	}
}