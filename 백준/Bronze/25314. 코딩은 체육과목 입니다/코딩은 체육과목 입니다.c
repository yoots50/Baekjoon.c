int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N / 4 + N % 4 != 0; i++) {
		printf("long ");
	}
	printf("int");
}