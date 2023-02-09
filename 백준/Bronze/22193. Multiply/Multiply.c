#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Complex {
	double r;
	double i;
}cplx;

void strReverse(char* str, int len) {
	char tmp;
	for (int i = 0; i < len / 2; i++) {
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
	}
}

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

void FFT(cplx* P, int n, int inv) {
	if (n == 1) {
		return;
	}

	double PI = acos(-1);
	int n2 = n / 2;

	cplx w;
	if (inv) {
		w.r = cos(2 * PI / n);
		w.i = -sin(2 * PI / n);
	}
	else {
		w.r = cos(2 * PI / n);
		w.i = sin(2 * PI / n);
	}

	cplx* e = (cplx*)malloc(sizeof(cplx) * n2);
	cplx* o = (cplx*)malloc(sizeof(cplx) * n2);

	for (int i = 0; i < n2; i++) {
		e[i] = P[2 * i];
		o[i] = P[2 * i + 1];
	}

	FFT(e, n2, inv);
	FFT(o, n2, inv);

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
	int N, M;
	scanf("%d%d", &N, &M);
	char* str1 = (char*)malloc(sizeof(char) * (N + 1));
	char* str2 = (char*)malloc(sizeof(char) * (M + 1));
	scanf("%s%s", str1, str2);

	if (str1[0] == '0' || str2[0] == '0') {
		printf("0");
		return 0;
	}

	int n = 1;

	while (n <= N || n <= M) {
		n <<= 1;
	}
	n <<= 1;

	strReverse(str1, N);
	strReverse(str2, M);
	
	cplx* P1 = (cplx*)malloc(sizeof(cplx) * n);
	cplx* P2 = (cplx*)malloc(sizeof(cplx) * n);
	for (int i = 0; i < n; i++) {
		P1[i].r = 0;
		P1[i].i = 0;
		P2[i].r = 0;
		P2[i].i = 0;
		if (i < N) {
			P1[i].r = str1[i] - '0';
		}
		if (i < M) {
			P2[i].r = str2[i] - '0';
		}
	}
	
	free(str1);
	free(str2);

	FFT(P1, n, 0);
	FFT(P2, n, 0);
	
	for (int i = 0; i < n; i++) {
		P1[i] = cplxmul(P1[i], P2[i]);
	}

	free(P2);
	FFT(P1, n, 1);
	
	for (int i = 0; i < n; i++) {
		P1[i].r /= n;
		P1[i].r = round(P1[i].r);
	}

	for (int i = 0; i < n - 1; i++) {
		P1[i + 1].r += (int)P1[i].r / 10;
		P1[i].r = (int)P1[i].r % 10;
	}

	int zeros = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (P1[i].r == 0) {
			zeros++;
		}
		else {
			break;
		}
	}

	for (int i = n - zeros - 1; i >= 0; i--) {
		printf("%d", (int)P1[i].r);
	}
}