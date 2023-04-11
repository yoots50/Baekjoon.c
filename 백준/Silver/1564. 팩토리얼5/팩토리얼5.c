int main() {
	int N;
	scanf("%d", &N);

	long long ans = 1;
	int cnt2 = 0, cnt5 = 0;
	int tmp;
	for (int i = 1; i <= N; i++) {
		tmp = i;

		while (!(tmp % 2)) {
			tmp /= 2;
			cnt2++;
		}

		while (!(tmp % 5)) {
			tmp /= 5;
			cnt5++;
		}
		ans *= tmp;
		ans %= 100000;
	}

	if (cnt2 > cnt5) {
		for (int i = 0; i < cnt2 - cnt5; i++) {
			ans *= 2;
			ans %= 100000;
		}
 	}

	else {	
		for (int i = 0; i < cnt5 - cnt2; i++) {
			ans *= 5;
			ans %= 100000;
		}
	}

	printf("%05d", ans);
}