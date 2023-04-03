int main() {
	int m, f;
	while (1) {
		scanf("%d%d", &m, &f);
		if (!(m || f)) {
			return 0;
		}
		printf("%d\n", m + f);
	}
}