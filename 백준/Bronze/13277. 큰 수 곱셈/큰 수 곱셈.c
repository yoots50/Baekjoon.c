#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1100000

void strReverse(char* str, int len) {
	char tmp;
	for (int i = 0; i < len / 2; i++) {
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

typedef struct Complex {
	double r;
	double i;
}cplx;

cplx cplxmul(cplx A, cplx B) {
	cplx newCplx;
	newCplx.r = A.r * B.r - A.i * B.i;
	newCplx.i = A.r * B.i + A.i * B.r;
	return newCplx;
}

cplx cplxadd(cplx A, cplx B) {
	cplx newCplx;
	newCplx.r = A.r + B.r;
	newCplx.i = A.i + B.i;
	return newCplx;
}

cplx cplxsub(cplx A, cplx B) {
	cplx newCplx;
	newCplx.r = A.r - B.r;
	newCplx.i = A.i - B.i;
	return newCplx;
}

void FFT(cplx* P, cplx w, int n) {
	if (n == 1) {
		return;
	}
	
	cplx* e = (cplx*)malloc(sizeof(cplx) * n);
	cplx* o = (cplx*)malloc(sizeof(cplx) * n);

	int eidx = 0;
	int oidx = 0;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 1) {
			o[oidx++] = P[i];
		}
		else {
			e[eidx++] = P[i];
		}
	}
	int n2 = n / 2;

	FFT(e, cplxmul(w, w), eidx);
	FFT(o, cplxmul(w, w), oidx);

	cplx wp = { 1, 0 };
	for (int i = 0; i < n2; i++) {
		P[i] = cplxadd(e[i], cplxmul(wp, o[i]));
		P[i + n2] = cplxsub(e[i], cplxmul(wp, o[i]));
		wp = cplxmul(wp, w);
	}
	free(e);
	free(o);
}

int main() {
	char* str1 = (char*)malloc(sizeof(char) * MAX);
	char* str2 = (char*)malloc(sizeof(char) * MAX);
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if (str1[0] == '0' || str2[0] == '0') {
		printf("0");
		return 0;
	}

	strReverse(str1, len1);
	strReverse(str2, len2);

	int n = 1;
	while (n <= len1 || n <= len2) {
		n <<= 1;
	}
	n <<= 1;

	cplx* P1 = (cplx*)malloc(sizeof(cplx) * n);
	cplx* P2 = (cplx*)malloc(sizeof(cplx) * n);

	for (int i = 0; i < len1; i++) {
		P1[i].r = str1[i] - 48;
		P1[i].i = 0;
	}

	for (int i = 0; i < len2; i++) {
		P2[i].r = str2[i] - 48;
		P2[i].i = 0;
	}

	for (int i = len1; i < n; i++) {
		P1[i].r = 0;
		P1[i].i = 0;
	}

	for (int i = len2; i < n; i++) {
		P2[i].r = 0;
		P2[i].i = 0;
	}

	free(str1);
	free(str2);

	double PI = acos(-1);
	cplx w1 = { cos(2 * PI / n), sin(2 * PI / n) };

	FFT(P1, w1, n);
	FFT(P2, w1, n);

	for (int i = 0; i < n; i++) {
		P1[i] = cplxmul(P1[i], P2[i]);
	}

	free(P2);

	cplx w2 = { cos(-2 * PI / n), sin(-2 * PI / n) };

	FFT(P1, w2, n);

	for (int i = 0; i < n; i++) {
		P1[i].r /= n;
		P1[i].r = round(P1[i].r);
	}
	for (int i = 0; i < len1 + len2; i++) {
		if (P1[i].r < 0) {
			P1[i].r = 0;
		}
		P1[i + 1].r += (int)P1[i].r / 10;
		P1[i].r = (int)P1[i].r % 10;
	}

	int zeros = n - 1;

	while ((int)P1[zeros].r == 0) {
		zeros--;
	}
	for (int i = zeros; i >= 0; i--) {
		printf("%d", (int)P1[i].r);
	}
	free(P1);
}