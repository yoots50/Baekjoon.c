#include <stdio.h>

int main() {
	int score;
	scanf("%d", &score);
	if (90 <= score && score <= 100) {
		printf("A");
		return 0;
	}
	else if (80 <= score && score <= 89) {
		printf("B");
		return 0;
	}
	else if (70 <= score && score <= 79) {
		printf("C");
		return 0;
	}
	else if (60 <= score && score <= 69) {
		printf("D");
		return 0;
	}
	else {
		printf("F");
		return 0;
	}
}