#include <stdio.h>
#include <stdlib.h>

int compare(void* a, void* b) {
	int A = *(int*)a;
	int B = *(int*)b;
	if (A < B) {
		return -1;
	}
	return A > B;
}

int main() {
	int arr[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, 3, sizeof(arr[0]), compare);

	printf("%d", arr[1]);
}