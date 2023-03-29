int main() {
	int num;
	scanf("%d", &num);

	int input;
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &input);
		if (input == num) {
			ans++;
		}
	}

	printf("%d", ans);
}