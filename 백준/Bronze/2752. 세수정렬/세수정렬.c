int main() {
	int first;
	int second;
	int third;
	int input;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &input);
		if (i == 0) {
			first = input;
		}
		else if (i == 1) {
			if (first < input) {
				second = input;
			}
			else {
				second = first;
				first = input;
			}
		}
		else {
			if (second < input) {
				third = input;
			}
			else if (first < input) {
				third = second;
				second = input;
			}
			else {
				third = second;
				second = first;
				first = input;
			}
		}
	}

	printf("%d %d %d", first, second, third);
}