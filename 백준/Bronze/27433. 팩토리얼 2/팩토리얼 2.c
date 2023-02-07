#include <stdio.h>
#include <string.h>
#define MAX_LEN 10000

char res[MAX_LEN];
char sumtmp[MAX_LEN];

void strsum(char* A, char* B) {
	char ans[MAX_LEN];
	int Aidx = strlen(A) - 1;
	int Bidx = strlen(B) - 1;
	int ansidx = MAX_LEN - 2;
	int sum;
	int carry = 0;

	ans[MAX_LEN - 1] = '\0';

	while (Aidx + 1 || Bidx + 1 || carry) {
		sum = 0;
		if (Aidx > -1) {
			sum += A[Aidx--] - 48;
		}
		if (Bidx > -1) {
			sum += B[Bidx--] - 48;
		}
		ans[ansidx--] = (sum + carry) % 10 + 48;
		carry = (sum + carry) / 10;
	}
	strcpy(sumtmp, ans + ansidx + 1);
}

void strmul(char* A, char* B) {
	char ans[MAX_LEN] = "0";
	char tmp[MAX_LEN];
	char* p;
	int tmpidx = MAX_LEN - 2;
	int Alen = strlen(A) - 1;
	int Blen = strlen(B) - 1;
	int Aidx = Alen, Bidx = Blen;
	int plus = 0;
	int mul = 0;
	int b = 0;

	tmp[MAX_LEN - 1] = '\0';

	while (Aidx + 1 || plus) {
		for (int i = 0; i < tmpidx - (Alen - Aidx); i++) {
			tmp[MAX_LEN - 2 - i] = '0';
		}
		mul = 0;
		if (Aidx > -1) {
			mul = A[Aidx--] - 48;
		}
		Bidx = Blen;
		while (Bidx + 1 || plus) {
			b = 0;
			if (Bidx > -1) {
				b = B[Bidx--] - 48;
			}
			tmp[tmpidx--] = (mul * b + plus) % 10 + 48;
			plus = (mul * b + plus) / 10;
		}
		strsum(tmp + tmpidx + 1, ans);
		strcpy(ans, sumtmp);
		tmpidx = MAX_LEN - 2 - (Alen - Aidx);
	}

	strcpy(res, ans);
}

int main() {
	int N;
	scanf("%d", &N);
	res[0] = '1';
	if (N == 0) {
		printf("1");
	}
	else {
		for (int i = 1; i <= N; i++) {
			char strN[3];
			if (i >= 10) {
				strN[0] = i / 10 + 48;
				strN[1] = i % 10 + 48;
				strN[2] = '\0';
			}
			else {
				strN[0] = i % 10 + 48;
				strN[1] = '\0';
			}
			strmul(res, strN);
			
		}
		printf("%s", res);
	}
}