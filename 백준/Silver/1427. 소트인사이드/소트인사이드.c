#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
	char A = *(char*)a;
	char B = *(char*)b;

	if (A > B) {
		return -1;
	}
	else if (A == B) {
		return 0;
	}
	return 1;
}

int main() {
	char str[11];
	scanf("%s", &str);
	qsort(str, strlen(str), sizeof(char), compare);
	printf("%s", str);
}