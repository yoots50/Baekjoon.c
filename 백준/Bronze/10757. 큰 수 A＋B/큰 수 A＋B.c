#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_LEN 10002

void strReverse(char* str) {
	char temp;
	int len = strlen(str) - 1;
	for (int i = 0; i < len / 2 + 1; i++) {
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
	}
}

int main() {
	char A[MAX_LEN], B[MAX_LEN];
	scanf("%s%s", &A, &B);

	strReverse(A);
	strReverse(B);

	int maxLen, minLen;
	int ALen = strlen(A);
	int BLen = strlen(B);

	if (ALen > BLen) {
		maxLen = ALen;
		minLen = BLen;
	}

	else {
		maxLen = BLen;
		minLen = ALen;
	}

	char ans[MAX_LEN];
	int plusOne = 0;
	int a, b;

	for (int i = 0; i < minLen; i++) {
		a = A[i] - 48;
		b = B[i] - 48;

		if (a + b + plusOne > 9) {
			ans[i] = a + b + plusOne - 10 + 48;
			plusOne = 1;
		}

		else {
			ans[i] = a + b + plusOne + 48;
			plusOne = 0;
		}
	}

	if (ALen == maxLen) {
		for (int i = minLen; i < maxLen; i++) {
			a = A[i] - 48;

			if (a + plusOne > 9) {
				ans[i] = a + plusOne - 10 + 48;
			}

			else {
				ans[i] = a + plusOne + 48;
				plusOne = 0;
			}
		}
	}

	if (BLen == maxLen) {
		for (int i = minLen; i < maxLen; i++) {
			b = B[i] - 48;

			if (b + plusOne > 9) {
				ans[i] = b + plusOne - 10 + 48;
			}

			else {
				ans[i] = b + plusOne + 48;
				plusOne = 0;
			}
		}
	}
	
	if (plusOne) {
		ans[maxLen] = '1';
		ans[maxLen + 1] = '\0';
	}

	else {
		ans[maxLen] = '\0';
	}

	strReverse(ans);
	printf("%s", ans);

}