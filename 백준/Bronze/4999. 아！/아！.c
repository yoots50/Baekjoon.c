#include <stdio.h>
#include <string.h>

int main() {
	char A[1001], B[1001];
	scanf("%s%s", &A, &B);
	if (strlen(A) < strlen(B)) {
		printf("no");
	}
	else {
		printf("go");
	}
}