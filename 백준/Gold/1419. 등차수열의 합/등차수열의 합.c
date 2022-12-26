#include <stdio.h>
#include <math.h>
int main() {
	int l, r, k;
	scanf("%d%d%d", &l, &r, &k);
	int ksum;
	ksum = (k * (k + 1)) / 2;
	if (r < ksum) {
		printf("0");
	}
	else {
		int cnt = 0;
		int min, max;
		for (int i = 0; ; i++) {
			if ((!(k * i % (ksum - k)) && i > 0 && k * i >= ksum - k) || r < ksum + k * i) {
				break;
			}
			if (l < ksum + k * i) {
				min = ksum + k * i;
			}
			else {
				min = ksum + k * i + ceil((double)(l - (ksum + k * i)) / (double)(ksum - k)) * (ksum - k);
			}
			max = ksum + k * i + floor((double)(r - (ksum + k * i)) / (double)(ksum - k)) * (ksum - k);
			cnt += (max - min) / (ksum - k) + 1;
		}
		printf("%d", cnt);
	}
}