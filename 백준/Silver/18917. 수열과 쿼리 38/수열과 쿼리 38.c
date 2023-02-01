#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 10000

char sum[MAX_LEN] = "0";

void strReverse(char* str) {
	char temp;
	int len = strlen(str) - 1;
	for (int i = 0; i < len / 2 + 1; i++) {
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
	}
}



void strsum(char* A, char* B) { 
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
	strcpy(sum, ans);
}

void strsub(char* A, char* B) { 
	strReverse(A);
	strReverse(B);

	int ALen = strlen(A);
	int BLen = strlen(B);

	char ans[MAX_LEN];
	int minusOne = 0;
	int a, b;

	for (int i = 0; i < BLen; i++) {
		a = A[i] - 48;
		b = B[i] - 48;

		if (a - b - minusOne < 0) {
			ans[i] = a - b - minusOne + 10 + 48;
			minusOne = 1;
		}

		else {
			ans[i] = a - b - minusOne + 48;
			minusOne = 0;
		}
	}

	for (int i = BLen; i < ALen; i++) {
		a = A[i] - 48;

		if (a - minusOne < 0) {
			ans[i] = a - minusOne + 10 + 48;
			minusOne = 1;
		}

		else {
			ans[i] = a - minusOne + 48;
			minusOne = 0;
		}
	}

	ans[ALen] = '\0';
	strReverse(ans);
	
	int cnt = 0;
	for (int i = 0; i < ALen - 1; i++) {
		if (ans[i] == '0') {
			cnt++;
		}
		
		else {
			break;
		}
	}
	strcpy(sum, ans + cnt);
}

int main() {

	int M;
	scanf("%d", &M);

	int XOR = 0;
	int cmd, arg;
	char strarg[MAX_LEN];
	for (int i = 0; i < M; i++) {

		scanf("%d", &cmd);

		if (cmd == 1) {
			scanf("%d", &arg);
			sprintf(strarg, "%d", arg);
			strsum(sum, strarg);
			XOR = (XOR ^ arg);
		}

		else if (cmd == 2) {
			scanf("%d", &arg);
			sprintf(strarg, "%d", arg);
			strsub(sum, strarg);
			XOR = (XOR ^ arg);
		}

		else if (cmd == 3) {
			printf("%s\n", sum);
		}
		
		else {
			printf("%d\n", XOR);
		}
	}
}