int main() {
	int input;
	int sum = 0;;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &input);
		sum += input;
	}
	printf("%d\n%d", sum / 60, sum % 60);
}