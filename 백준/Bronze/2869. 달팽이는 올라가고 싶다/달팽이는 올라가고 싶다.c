#include <stdio.h>

int main() {
	int A, B, V;
	scanf("%d%d%d", &A, &B, &V);
	int temp = (V - B) / (A - B) - 1;
	for (int i = temp; ; i++) {
		if (V <= (A - B) * i + A) {
			printf("%d", i + 1);
			return 0;
		}
	}
}