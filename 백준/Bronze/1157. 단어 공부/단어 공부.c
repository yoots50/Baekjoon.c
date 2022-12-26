#include <stdio.h>

int main() {
	char str[1000001];
    int alpha[28] = {0};
	scanf("%s", str);
	for (int i = 0; i < 1000001; i++) {
		if (97 <= str[i] && str[i] <= 122) {
			alpha[str[i] - 97]++;
		}
		else {
			alpha[str[i] - 65]++;
		}
		if (str[i] == '\0') {
			break;
		}
	}
	int max = alpha[0];
	int idx = 0;
	for (int i = 1; i < 27; i++) {
		if (max < alpha[i]) {
			max = alpha[i];
			idx = i;
		}
	}
	for (int i = 1; i < 27; i++) {
		if (max == alpha[i] && i != idx) {
			printf("?");
			return 0;
		}
	}
	printf("%c", idx + 65);
}