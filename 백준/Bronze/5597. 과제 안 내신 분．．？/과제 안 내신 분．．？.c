int main() {
	int arr[28];
	int	table[30];
	for (int i = 0; i < 30; i++) {
		table[i] = i + 1;
	}
	for (int i = 0; i < 28; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 28; i++) {
		table[arr[i] - 1] = 0;
	}
	for (int i = 0; i < 30; i++) {
		if (table[i] != 0) {
			printf("%d\n", table[i]);
		}
	}
}