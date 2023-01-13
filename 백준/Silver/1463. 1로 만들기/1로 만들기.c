#include <stdio.h>

int memo[1000001] = { 0, };

int func(int N) {
	if (N == 1) {
		return 0;
	}
	if (memo[N] != 0) {
		return memo[N];
	}
	int func1 = func(N - 1);
	int func2;
	int func3;
	int min = func1;
	if (!(N % 6)) {
		func2 = func(N / 2);
		func3 = func(N / 3);
		min = min < func2 ? min : func2;
		min = min < func3 ? min : func3;
		memo[N] = min + 1;
		return min + 1;
	}
	if (!(N % 3)) {
		func3 = func(N / 3);
		min = min < func3 ? min : func3;
		memo[N] = min + 1;
		return min + 1;
	}
	if (!(N % 2)) {
		func2 = func(N / 2);
		min = min < func2 ? min : func2;
		memo[N] = min + 1;
		return min + 1;
	}
	memo[N] = min + 1;
	return min + 1;
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d", func(N));
}