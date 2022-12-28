#include <stdio.h>
#include <math.h>
int isright(int a, int b, int c) {
	int max = a;
	max = max < b ? b : max;
	max = max < c ? c : max;
	if (max == a) {
		return pow(a, 2) == pow(b, 2) + pow(c, 2);
	}
	else {
		if (max == b) {
			return pow(b, 2) == pow(a, 2) + pow(c, 2);
		}
		return pow(c, 2) == pow(a, 2) + pow(b, 2);
	}
}

int main() {
	int a, b, c;
	while (1) {
		scanf("%d%d%d", &a, &b, &c);
		if (!a && !b && !c) {
			return 0;
		}
		if (isright(a, b, c)) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
}