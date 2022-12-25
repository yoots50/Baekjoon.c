#include <stdio.h>
#include <math.h>

int func(int n) {
	int answer = 0;
	if (n <= 1) {
		answer = n;
	}
	else {
		for (int i = 0; i < (int)log2(n) + 1; i++) {
			if (n % (int)pow(2, i + 1) >= (int)pow(2, i + 1) / 2) {
				answer += (int)pow(4, i);
			}
		}
	}
	return answer;
}

int main() {

	int N, r, c;
	scanf("%d%d%d", &N, &r, &c);
	int row, col;
	
	col = func(c);
	row = 2 * func(r);
	printf("%d", (row + col));
}
