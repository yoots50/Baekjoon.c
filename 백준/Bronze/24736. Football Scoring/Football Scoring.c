int main() {
	int T, F, S, P, C;
	for (int i = 0; i < 2; i++) {
		scanf("%d%d%d%d%d", &T, &F, &S, &P, &C);
		printf("%d ", 6 * T + 3 * F + 2 * S + P + 2 * C);
	}
}