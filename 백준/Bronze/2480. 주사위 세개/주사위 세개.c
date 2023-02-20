#include <stdio.h>

int main() {
	int f, s, t;
	scanf("%d%d%d", &f, &s, &t);
	if (f == s && s == t) {
		printf("%d", 10000 + f * 1000);
		return 0;
	}
	if (f == s || f == t) {
		printf("%d", 1000 + f * 100);
		return 0;
	}
	if (s == t) {
		printf("%d", 1000 + t * 100);
		return 0;
	}
	int max = 0;
	if (f > max) {
		max = f;
	}
	if (s > max) {
		max = s;
	}
	if (t > max) {
		max = t;
	}
	printf("%d", max * 100);
}
