#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	int H, W, N;
	for (int i = 0; i < T; i++) {
		scanf("%d%d%d", &H, &W, &N);
		int heightnum = N % H;
		int widthnum = N / H + 1;
		if (heightnum == 0) {
			heightnum = H;
			widthnum--;
		}
		if (widthnum < 10) {
			printf("%d0%d\n", heightnum, widthnum);
		}
		else {
			printf("%d%d\n", heightnum, widthnum);
		}
	}
}