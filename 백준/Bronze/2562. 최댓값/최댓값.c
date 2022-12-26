#include <stdio.h>

int main() {
	int arr[10] = {0};
	int idx = 0;
	int max = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		if (i == 0) {
			max = arr[i];
			idx = i;
		}
		else {
			if (max < arr[i]) {
				idx = i;
				max = arr[i];
			}
		}
	}
	printf("%d\n%d", max, idx + 1);
}