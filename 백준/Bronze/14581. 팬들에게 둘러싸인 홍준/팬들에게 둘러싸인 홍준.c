int main() {
	char id[21];
	scanf("%s", &id);
	for (int i = 1; i <= 9; i++) {
		if (i == 5) {
			printf(":%s:", id);
		}
		else {
			printf(":fan:");
		}
		if (!(i % 3)) {
			printf("\n");
		}
	}
}