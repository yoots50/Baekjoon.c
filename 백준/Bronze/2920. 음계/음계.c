#include <stdio.h>

int main() {
	int arr[16];
	int acnt = 0, dcnt = 0;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[2 * i]);
		if (arr[2 * i] == i + 1) {
			acnt++;
		}
		if (arr[2 * i] == 8 - i) {
			dcnt++;
		}
	}
	if (acnt == 8) {
		printf("ascending");
	}
	else if (dcnt == 8) {
		printf("descending");
	}
	else {
		printf("mixed");
	}
}