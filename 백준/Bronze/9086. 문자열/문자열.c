#include <stdio.h>
#include <string.h>
int main() {
	int T;
	scanf("%d", &T);
	char str[1000];
	int length = 0;
	for (int i = 0; i < T; i++) {
		length = 0;
		scanf("%s", &str);
		for (int j = 0; ; j++) {
			if (str[length]) {
				length++;
			}
			else {
				break;
			}
		}
		printf("%c%c\n", str[0], str[length - 1]);
	}
}