#include <stdio.h>
#include <math.h>
int isPalindrom(int n) {
	int length = floor(log10(n) + 1);
	int first, last;
	for (int i = 0; i < (int)floor(length / 2); i++) {
		if (i == 0) {
			first = n / (int)pow(10, length - i - 1);
		}
		else {
			first = (n / (int)pow(10, length - i - 1)) % 10;
		}
		last = (n % (int)pow(10, i + 1)) / (int)pow(10, i);
		if (first != last) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int scan;
	while (1) {
		scanf("%d", &scan);
		if (scan == 0) {
			return 0;
		}
		if (isPalindrom(scan)) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}