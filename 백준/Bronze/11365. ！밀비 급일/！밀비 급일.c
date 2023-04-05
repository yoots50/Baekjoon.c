#include <stdio.h>
#include <string.h>

int main() {
	char str[501];
	while (1) {
		scanf("%[^\n]s", str);
		if (!strcmp(str, "END")) {
			break;
		}

		for (int i = strlen(str) - 1; i >= 0; i--) {
			printf("%c", str[i]);
		}
		printf("\n");
		getchar();
	}
}