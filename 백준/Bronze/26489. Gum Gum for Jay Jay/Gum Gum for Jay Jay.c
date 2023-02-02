#include <stdio.h>

int main() {
	char input[100];
	int cnt = 0;
	while (fgets(input, 100, stdin) != NULL) {
		cnt++;
	}
	printf("%d", cnt);
}