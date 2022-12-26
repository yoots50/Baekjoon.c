#include <stdio.h>
#include <math.h>

int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	int Ar = 0, Br = 0;
	for (int i = 0; i < 3; i++) {
		Ar += (A % 10) * pow(10, 2 - i);
		Br += (B % 10) * pow(10, 2 - i);
		A /= 10;
		B /= 10;
	}
	printf("%d", Ar > Br ? Ar : Br);
}