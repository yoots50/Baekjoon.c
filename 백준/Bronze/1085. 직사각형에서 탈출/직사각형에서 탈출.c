#include <stdio.h>

int main() {
	int x, y, w, h;
	scanf("%d%d%d%d", &x, &y, &w, &h);
	int up, down, left, right;
	up = h - y;
	down = y;
	right = w - x;
	left = x;
	int min = up;
	min = min > down ? down : min;
	min = min > right ? right : min;
	min = min > left ? left : min;
	printf("%d", min);
}