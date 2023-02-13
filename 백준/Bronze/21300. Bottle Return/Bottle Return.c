int main() {
	int input;
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		scanf("%d", &input);
		sum += input * 5;
	}
	printf("%d", sum);
}