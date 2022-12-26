#include <stdio.h>

int main() {
	char arr[10];
	scanf("%[^\n]s", arr);
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		arr[2 * i] -= 48;
		sum += arr[2 * i] * arr[2 * i];
	}
	printf("%d", sum % 10);
}