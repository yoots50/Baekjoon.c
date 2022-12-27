#include <stdio.h>
#include <ctype.h>

int main() {
	char str[101];
	scanf("%s", &str);
	for (int i = 0; i < 101; i++) {
		if (!str[i]) {
			break;
		}
		else {
			if (isupper(str[i])) {
				str[i] = tolower(str[i]);
			}
			else {
				str[i] = toupper(str[i]);
			}
		}
	}
	printf("%s", str);
}