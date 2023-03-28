int main() {
	int N;
	int two = 0;
	int five = 0;

	scanf("%d", &N);

	int tmp;
	for (int i = 1; i <= N; i++) {
		tmp = i;
		while (!(tmp % 5)) {
			tmp /= 5;
			five++;
		}
		while (!(tmp % 2)) {
			tmp /= 2;
			two++;
		}
	}

	if (five < two) {
		printf("%d", five);
	}

	else {
		printf("%d", two);
	}
}