#include <stdio.h>

int isYoon(int year) {
	return ((!(year % 4)) && (year % 100)) || (!(year % 400));
}

int dayInMonth(int year, int month) {
	if (month <= 7) {
		if (month % 2) {
			return 31;
		}
		if (month == 2) {
			if (isYoon(year)) {
				return 29;
			}
			return 28;
		}
		return 30;
	}
	if (month % 2) {
		return 30;
	}
	return 31;
}

int diff(int y1, int m1, int d1, int y2, int m2, int d2) {
	int ret = 0;
	int r = 0, l = 0;

	if (y1 + 1000 < y2 || (y1 + 1000 == y2 && m1 < m2) || (y1 + 1000 == y2 && m1 == m2 && d1 <= d2)) {
		return -1;
	}

	if (y1 < y2) {
		for (int i = m1; i <= 12; i++) {
			r += dayInMonth(y1, i);
		}
		r -= d1;

		for (int i = 1; i < m2; i++) {
			l += dayInMonth(y2, i);
		}
		l += d2;

		for (int i = y1 + 1; i < y2; i++) {
			if (isYoon(i)) {
				ret += 366;
			}
			else {
				ret += 365;
			}
		}

		return ret += r + l;
	}

	else {
		for (int i = 1; i < m1; i++) {
			r += dayInMonth(y1, i);
		}
		r += d1;

		for (int i = 1; i < m2; i++) {
			l += dayInMonth(y2, i);
		}
		l += d2;
	}

	return ret += l - r;
}

int main() {
	int y1, m1, d1, y2, m2, d2;
	scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2);
	int df = diff(y1, m1, d1, y2, m2, d2);

	if (df == -1) {
		printf("gg");
		return 0;
	}

	printf("D-%d", df);
}