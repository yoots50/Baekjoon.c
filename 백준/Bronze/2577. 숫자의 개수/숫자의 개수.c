#include <stdio.h>

int main() {
	int arr[10] = { 0 };
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	int result;
	result = A * B * C;
	while (result) {
		arr[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
}