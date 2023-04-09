int main() {
	char ch;
	char tf = 0;
	int cnt[2] = { 0, };
	while ((ch = getchar()) != '\n') {
		if (ch != tf) {
			tf = ch;
			cnt[ch - '0']++;
		}
	}

	printf("%d", cnt[0] > cnt[1] ? cnt[1] : cnt[0]);
}