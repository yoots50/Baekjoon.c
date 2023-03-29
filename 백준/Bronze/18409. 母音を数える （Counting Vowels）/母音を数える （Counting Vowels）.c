int main() {
	char ch;
	while ((ch = getchar()) != '\n') {

	}
	int ans = 0;
	while ((ch = getchar()) != '\n') {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			ans++;
		}
	}

	printf("%d", ans);
}