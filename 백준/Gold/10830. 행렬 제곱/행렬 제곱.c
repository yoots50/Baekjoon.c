#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int matrix;

void print_matrix(matrix** A, long long N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

int check_memo(matrix*** memo, long long N, long long B) {
	if (memo[B][0][0] == -1) {
		return 0;
	}

	return 1;
}

matrix** mul_matrix(matrix** A, matrix** B, long long N, long long M) {
	matrix** ret = (matrix**)malloc(sizeof(matrix**) * N);
	for (int i = 0; i < N; i++) {
		ret[i] = (matrix*)malloc(sizeof(matrix*) * N);
		for (int j = 0; j < N; j++) {
			matrix aij = 0;

			for (int k = 0; k < N; k++) {
				aij += (A[i][k] * B[k][j]) % M;
			}

			ret[i][j] = aij % M;
		}
	}

	return ret;
}

matrix** I_matrix(long long N) {
	matrix** I = (matrix**)malloc(sizeof(matrix*) * N);

	for (int i = 0; i < N; i++) {
		I[i] = (matrix*)malloc(sizeof(matrix) * N);

		for (int j = 0; j < N; j++) {
			if (i == j) {
				I[i][j] = 1;
			}

			else {
				I[i][j] = 0;
			}
		}
	}

	return I;
}

matrix** pow_matrix(matrix** A, long long B, long long N, long long M, matrix*** memo) {
	if (B < 1) {
		return I_matrix(N);
	}

	if (B == 1) {
		return mul_matrix(A, I_matrix(N), N, M);
	}

	const long long log2B = log2(B);
	const long long pow2B = pow(2, log2B);

	if (check_memo(memo, N, log2B - 1)) {
		return mul_matrix(memo[log2B - 1], pow_matrix(A, B - pow2B, N, M, memo), N, M);
	}

	memo[log2B - 1] = mul_matrix(pow_matrix(A, pow2B / 2, N, M, memo), pow_matrix(A, pow2B / 2, N, M, memo), N, M);
	return mul_matrix(memo[log2B - 1], pow_matrix(A, B - pow2B, N, M, memo), N, M);
}

int main() {
	long long N;
	long long B;
	scanf("%lld%lld", &N, &B);

	matrix** A = (matrix**)malloc(sizeof(matrix*) * N);
	for (int i = 0; i < N; i++) {
		A[i] = (matrix*)malloc(sizeof(matrix) * N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	const long long log2B = log2(B);
	matrix*** memo = (matrix***)malloc(sizeof(matrix**) * log2B);
	for (int i = 0; i < log2B; i++) {
		memo[i] = (matrix**)malloc(sizeof(matrix*) * N);
		for (int j = 0; j < N; j++) {
			memo[i][j] = (matrix*)malloc(sizeof(matrix) * N);
			for (int k = 0; k < N; k++) {
				memo[i][j][k] = -1;
			}
		}
	}

	print_matrix(pow_matrix(A, B, N, 1000, memo), N);
}