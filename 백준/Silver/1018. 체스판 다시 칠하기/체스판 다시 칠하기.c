#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	char** arr = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (char*)malloc(sizeof(char) * M);
		scanf("%s", arr[i]);
	}
	int Bcnt = 0;
	int Wcnt = 0;
	int max = -1;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if (arr[k][l] == 'B') {
						if (!((k + l + 2) % 2)) {
							Bcnt++;
						}
						else {
							Wcnt++;
						}
					}
					else {
						if ((k + l + 2) % 2) {
							Bcnt++;
						}
						else {
							Wcnt++;
						}
					}
				}
			}
			max = max < Bcnt ? Bcnt : max;
			max = max < Wcnt ? Wcnt : max;
			Bcnt = 0;
			Wcnt = 0;
		}
	}
	printf("%d", (64 - max));
}