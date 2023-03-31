int main() {
	int apples[4];
	int input;
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &apples[i]);
	}
	for (int i = 0; i < 3; i++) {
		scanf("%d", &input);
		for (int i = 0; i < 4; i++) {
			if (apples[i] == input) {
				ans = i + 1;
			}
		}
	}
	printf("%d", ans);
}