#include <stdio.h>

int GCDfunc(int A, int B) {
	int temp;
	int a = A, b = B;
	while (1) {
		temp = b;
		b = a % b;
		a = temp;
		if (b == 0) {
			break;
		}
	}
	return a;
}

long long int LCMfunc(int A, int B) {
	long long int ka = 1, kb = 1;
	while (1) {
		if (A * ka == B * kb) {
			return A * ka;
		}
		else {
			while (A * ka < B * kb) {
				ka++;
			}
			while (A * ka > B * kb) {
				kb++;
			}
		}
	}
}

int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	int GCD;
	long long int LCM;
	GCD = GCDfunc(A, B);
	printf("%d\n", GCD);
	LCM = LCMfunc(A, B);
	printf("%lld\n", LCM);
}