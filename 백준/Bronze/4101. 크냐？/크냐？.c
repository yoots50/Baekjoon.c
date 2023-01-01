#include <stdio.h>

int main() {
	int A, B;
	while (1) {
		scanf("%d%d", &A, &B);
		if (A == 0 && B == 0) {
			return 0;
		}
		if (A > B) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}