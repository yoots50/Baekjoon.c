int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a == b && b == c && c == 60) {
		printf("Equilateral");
	}
	else if (a + b + c == 180) {
		if (a == b || b == c || a == c) {
			printf("Isosceles");
		}
		else {
			printf("Scalene");
		}
	}
	else {
		printf("Error");
	}
}