#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int cnt = 0;
	int newN = N;
	do {
		newN = (newN % 10) * 10 + (newN / 10 + newN % 10) % 10;
		cnt++;
	} while (N != newN);
	printf("%d", cnt);
}