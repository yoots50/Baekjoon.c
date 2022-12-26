#include <stdio.h>

int main() {
	int year;
	scanf("%d", &year);
	if (!(year % 4) && ((year % 100) || !(year % 400))) {
		printf("1");
		return 0;
	}
	printf("0");
}