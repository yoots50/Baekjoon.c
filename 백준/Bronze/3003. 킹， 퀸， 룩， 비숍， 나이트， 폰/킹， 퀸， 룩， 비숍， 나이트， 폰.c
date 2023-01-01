#include <stdio.h>

int main() {
	int k, q, r, b, kn, p;
	scanf("%d%d%d%d%d%d", &k, &q, &r, &b, &kn, &p);
	printf("%d %d %d %d %d %d", (1 - k), (1 - q), (2 - r), (2 - b), (2 - kn), (8 - p));
}