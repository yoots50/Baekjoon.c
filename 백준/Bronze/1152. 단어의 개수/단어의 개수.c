#include <stdio.h>

int main() {
	char str[1000001];
	scanf("%[^\n]s", str);
	int cnt = 0;
	if (str[0] == '\0' || (str[0] == ' ' && (str[1] == '\0' || str[1] == ' '))) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < 1000000; i++) {
		if ((str[i] == ' ' && i != 0) && str[i + 1] != '\0') {
			cnt++;
		}
		if (str[i] == '\0') {
			break;
		}
	}
	printf("%d", cnt + 1);
}