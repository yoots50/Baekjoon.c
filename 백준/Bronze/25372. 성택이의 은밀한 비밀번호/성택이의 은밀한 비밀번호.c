#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);

	char str[21];

	for (int i = 0; i < N; i++) {
		scanf("%s", &str);
		int len = strlen(str);

		if (6 <= len && len <= 9) {
			printf("yes\n");
		}
		
		else {
			printf("no\n");
		}
	}
}