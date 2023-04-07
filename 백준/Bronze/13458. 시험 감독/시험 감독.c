#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);

	int* people = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &people[i]);
	}

	int B, C;
	scanf("%d%d", &B, &C);

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		people[i] -= B;
		ans++;
		if (people[i] > 0) {
			if (people[i] < C) {
				ans++;
			}

			else if (people[i] % C) {
				ans += people[i] / C + 1;
			}

			else {
				ans += people[i] / C;
			}
		}
	}

	printf("%lld", ans);
}
