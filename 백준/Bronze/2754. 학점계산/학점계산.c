#include <stdio.h>

int main() {
	char str[3];
	scanf("%s", &str);
	float sum = 0.0;
	if (str[0] == 'F') {
		printf("%.1f", sum);
		return 0;
	}
	sum += (4 - (str[0] - 65));
	if (str[1] == '+') {
		sum += 0.3;
	}
	else if (str[1] == '-') {
		sum -= 0.3;
	}
	printf("%.1f", sum);
}