#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		char arr[81];
		int cnt = 1;
		int sum = 0;
		scanf("%s", arr);
		for (int j = 0; ; j++) {
			if (arr[j] == '\0') {
				break;
			}
			else {
				if (arr[j] == (char)'O') {
					sum += cnt;
					cnt++;
				}
				else {
					cnt = 1;
				}
			}
		}
		printf("%d\n", sum);
	}
}