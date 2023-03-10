#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long func(long long A, long long B, long long C, long long* memo) {
	if (B < 1) {
		return 1;
	}
	if (B == 1) {
		return A % C;
	}
	long long logB = log2(B);
	long long powB = pow(2, logB);
	if (memo[logB - 1] != -1) {
		return ((memo[logB - 1] % C) * (func(A, B - powB, C, memo) % C)) % C;
	}
	memo[logB - 1] = ((func(A, powB / 2, C, memo) % C) * (func(A, powB / 2, C, memo) % C)) % C;
	return ((memo[logB - 1] % C) * (func(A, B - powB, C, memo) % C)) % C;
}

int main() {
	long long A, B, C;
	scanf("%lld%lld%lld", &A, &B, &C);

	const long long clogB = log2(B);
	
	long long* memo = (long long*)malloc(sizeof(long long) * clogB);

	for (long long i = 0; i < clogB; i++) {
		memo[i] = -1;
	}

	printf("%lld", func(A, B, C, memo));
}