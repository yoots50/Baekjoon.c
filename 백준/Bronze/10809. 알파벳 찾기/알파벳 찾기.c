#include <stdio.h>

int main() {
	int alpha[26];
	for (int i = 0; i < 26; i++) {
		alpha[i] = -1;
	}
	char str[100];
	scanf("%s", str);
	for (int i = 0; ; i++) {
		if (str[i] == '\0') {
			break;
		}
		if (alpha[str[i] - 97] == -1) {
			alpha[str[i] - 97] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alpha[i]);
	}
}