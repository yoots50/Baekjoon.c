#include <stdio.h>

int main() {
	long long int x, y;
	scanf("%lld%lld", &x, &y);
	if (x - y >= 0) {
		printf("%lld", (x - y));
	}
	else {
		printf("%lld", (y - x));
	}
}