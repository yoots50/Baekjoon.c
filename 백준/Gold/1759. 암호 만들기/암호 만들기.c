#include <stdio.h>
#include <stdlib.h>

void func(int alpha[], int L, int cnt, char* str, int vcnt, int ccnt, int start) {
	if (cnt == L && vcnt >= 1 && ccnt >= 2) {
		str[L] = '\0';
		printf("%s\n", str);
		return;
	}

	for (int i = start; i < 26; i++) {
		if (alpha[i]) {
			alpha[i]--;
			str[cnt] = i + 'a';
			if (str[cnt] == 'a' || str[cnt] == 'e' || str[cnt] == 'i' || str[cnt] == 'o' || str[cnt] == 'u') {
				func(alpha, L, cnt + 1, str, vcnt + 1, ccnt, i + 1);
			}
			else {
				func(alpha, L, cnt + 1, str, vcnt, ccnt + 1, i + 1);
			}
			alpha[i]++;
		}
	}
	return;
}

int main() {
	int L, C;
	scanf("%d%d", &L, &C);

	int alpha[26] = { 0, };

	getchar();
	char ch;
	while ((ch = getchar()) != '\n') {
		if ('a' <= ch && ch <= 'z') {
			alpha[ch - 'a']++;
		}
	}

	char* str = malloc(sizeof(char) * L);
	str[L] = '\0';
	func(alpha, L, 0, str, 0, 0, 0);
}