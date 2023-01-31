#include <stdio.h>

int main() {
	int T, S;
	scanf("%d%d", &T, &S);

	if (T <= 11) {
		printf("280");
	}
	else if (T <= 16) {
		if (S) {
			printf("280");
		}
		else {
			printf("320");
		}
	}
	else {
		printf("280");
	}
}