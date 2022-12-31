#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	if (n == 1) {
		return 0;
	}
	for (int i = 2; i < n; i++) {
		if (!(n % i)) {
			return 0;
		}
	}
	return 1;
}

int isPalindrome(int n, int length) {
	int first = n / pow(10, length - 1);
	int last = n % 10;
	if (length <= 2 && (first == last)) {
		return 1;
	}
	else if (first != last) {
		return 0;
	}
	else {
		return isPalindrome((n - first - last * pow(10, length - 1)) / 10, length - 2);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int length;
	for (int i = N; ; i++) {
		length = floor(log10(i) + 1);
		if (isPalindrome(i, length) && isPrime(i)) {
			printf("%d", i);
			return 0;
		}
	}
}
