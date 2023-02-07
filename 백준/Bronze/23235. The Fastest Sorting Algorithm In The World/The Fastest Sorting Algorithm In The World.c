#include <stdio.h>

int main() {
	int i = 1;
	char input[10000];
	while (1) {
		fgets(input, 10000, stdin);
		if (input[0] == '0' && input[1] == '\n') {
			break;
		}
		printf("Case %d: Sorting... done!\n", i++);
	}
}