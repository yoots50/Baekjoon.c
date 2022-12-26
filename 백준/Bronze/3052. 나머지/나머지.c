#include <stdio.h>

int main() {
	int arr[10];
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
		arr[i] %= 42;
	}
	int idx;
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (arr[i] == arr[j] && j != i && arr[j] != 42) {
				cnt++;
				idx = i;
				arr[j] = 42;
			}
		}
	}
	printf("%d", 10 - cnt);
}