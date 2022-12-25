#include <stdio.h>
#include <math.h>

int main() {
	int T;
	int x, y;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &x, &y);
		int d = y - x;
		int go = (int)sqrt(d);
		int gosum;
		if (go * go == d) {
			gosum = 2 * go - 1;
			printf("%d\n", gosum);
		}
		else {
			gosum = 2 * go - 1;
			if ((d - go * go) % go != 0) {
				gosum += (d - go * go) / go + 1;
				printf("%d\n", gosum);
			}
			else {
				gosum += (d - go * go) / go;
				printf("%d\n", gosum);
			}
		}
	}
}