int main() {
	int L, P;
	scanf("%d%d", &L, &P);

	int input;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &input);
		printf("%d ", input - L * P);
	}
}