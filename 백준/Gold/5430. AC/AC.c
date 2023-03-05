#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int T;
	scanf("%d", &T);

	char funcs[100001];
	int n;
	char str[500000];
	int newStr[100001];
	char* end;
	for (int i = 0; i < T; i++) {
		scanf("%s", &funcs);
		scanf("%d", &n);
		scanf("%s", &str);
		int start = 0;
		int last = 0;
		int isRev = 0;
		int error = 0;
		int funcslen = strlen(funcs);
		int len = strlen(str) - 1;
		str[len--] = '\0';
		char* ptr = strtok(str + 1, ",");
		while (ptr != NULL) {
			newStr[last++] = strtol(ptr, &end, 10);
			ptr = strtok(NULL, ",");
		}

		for (int j = 0; j < funcslen; j++) {
			if (funcs[j] == 'R') {
				if (isRev) {
					isRev = 0;
				}
				else {
					isRev = 1;
				}
			}
			else {
				if (isRev) {
					last--;
				}
				else {
					start++;
				}
				if (start > last) {
					error = 1;
				}
			}
		}

		if (error) {
			printf("error\n");
		}

		else {
			if (isRev) {
				printf("[");
				for (int j = last - 1; j >= start; j--) {
					printf("%d", newStr[j]);
					if (j != start) {
						printf(",");
					}
				}
				printf("]\n");
			}
			else {
				printf("[");
				for (int j = start; j < last; j++) {
					printf("%d", newStr[j]);
					if (j != last - 1) {
						printf(",");
					}
				}
				printf("]\n");
			}
		}
	}
}