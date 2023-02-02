int main() {
	int n;
	scanf("%d", &n);
	int num;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		sum += num;
	}
	printf("%d", sum);
}