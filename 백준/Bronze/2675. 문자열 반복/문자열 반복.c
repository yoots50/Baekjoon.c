#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	char str[23];
	for (int i = 0; i < T; i++) {
		getchar();
		scanf("%[^\n]s", str);
		int idx = 2;
		while (str[idx]) {
			for (int j = 0; j < str[0] - 48; j++) {
				printf("%c", str[idx]);
			}
			idx++;
		}
		printf("\n");
	}
}