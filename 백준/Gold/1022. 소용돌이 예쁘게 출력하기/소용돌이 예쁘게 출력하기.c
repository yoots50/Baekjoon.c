#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int A = *(int*)a;
	int B = *(int*)b;
	if (A < B) {
		return -1;
	}
	return A > B;
}

int func(int i, int j) {
	int max = i > j ? i : j;
	int absmax = abs(i) > abs(j) ? abs(i) : abs(j);;
	int base = (2 * (absmax + 1) - 1) * (2 * (absmax + 1) - 1);
	if (i == j) {
		if (i >= 0) {
			return base;
		}
		return base - absmax * 4;
	}
	if (i == max) {
		if (i == absmax) {
			return base + (j - absmax);
		}
		return base - 2 * absmax + (i - absmax);
	}
	if (j == max) {
		base -= absmax * 4;
		if (j == absmax) {
			return base - 2 * absmax - (i + absmax);
		}
		return base - (j + absmax);
	}
}

int main() {
	int r1, r2, c1, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	int arr[4] = {func(r1, c1), func(r1, c2), func(r2, c1), func(r2, c2)};
	qsort(arr, 4, 4, compare);
	int maxlen = floor(log10(arr[3]) + 1);
	int printout;
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			printout = func(i, j);
			for (int k = 0; k < maxlen - floor(log10(printout) + 1); k++) {
				printf(" ");
			}
			if (j == c2) {
				printf("%d\n", printout);
			}
			else {
				printf("%d ", func(i, j));
			}
		}
	}
}