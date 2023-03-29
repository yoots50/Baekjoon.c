int main() {
	char ch;
	int arr[26] = { 0, };
	while ((ch = getchar()) != '\n') {
		arr[ch - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", arr[i]);
	}
}