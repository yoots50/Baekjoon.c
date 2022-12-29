#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
	char* str1 = *(char**)a;
	char* str2 = *(char**)b;
	if (strlen(str1) == strlen(str2)) {
		return strcmp(str1, str2);
	}
	else {
		if (strlen(str1) > strlen(str2)) {
			return 1;
		}
		return -1;
	}
	
}

int main() {
	int N;
	scanf("%d", &N);
	
	char** str = (char**)malloc(sizeof(char*) * N);
	
	for (int i = 0; i < N; i++) {
		str[i] = (char*)malloc(sizeof(char) * 51);
		scanf("%s", str[i]);
	}

	qsort(str, N, sizeof(str[0]), compare);

	for (int i = 0; i < N; i++) {
		if (i == N - 1 || strcmp(str[i], str[i + 1])) {
			printf("%s\n", str[i]);
		}
	}
}