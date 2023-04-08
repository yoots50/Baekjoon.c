int main() {
	int L, A, B, C, D;
	scanf("%d%d%d%d%d", &L, &A, &B, &C, &D);

	int d1 = A / C + (A % C != 0);
	int d2 = B / D + (B % D != 0);

	if (d1 > d2) {
		printf("%d", L - d1);
	}

	else {
		printf("%d", L - d2);
	}
}