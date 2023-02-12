int main() {
	int N;
	scanf("%d", &N);
	int x, y;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &x, &y);
		printf("%d\n", x + y);
	}
}