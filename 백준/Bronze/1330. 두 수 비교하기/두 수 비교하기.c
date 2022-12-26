#include <stdio.h>

int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	if (A == B) {
		printf("==");
	}
	else {
		A > B ? printf(">") : printf("<");
	}
}