#include <stdio.h>

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	char ch;
	int tf = 1, cnt = 0, ans = 0;
	getchar();
	while ((ch = getchar()) != '\n') {
		if ((ch == 'I' && tf) || (ch == 'O' && !tf)) {
			tf = tf ? 0 : 1;
			cnt++;
		}
		else {
			if (ch == 'I') {
				cnt = 1;
				tf = 0;
			}
			else {
				cnt = 0;
				tf = 1;
			}
		}
		if (cnt == N * 2 + 1) {
			cnt -= 2;
			ans++;
		}
	}

	printf("%d", ans);
}