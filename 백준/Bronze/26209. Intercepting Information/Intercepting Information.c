int main() {
	int N;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &N);
		if (!(N == 1 || N == 0)) {
			printf("F");
			return 0;
		}
	}
	printf("S");
}