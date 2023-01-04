#include <stdio.h>
#include <string.h>

int func(char* str) {
	int cnt1 = 0;
	int cnt2 = 0;
	char temp[101];
	int idx = 0;
	for (int i = 0; i < strlen(str); i++) {
		if ((cnt1 == 0 && str[i] == ')') || (cnt2 == 0 && str[i] == ']')) {
			return 0;
		}
		else if (str[i] == '(') {
			cnt1++;
			temp[idx] = '(';
			idx++;
		}
		else if (str[i] == '[') {
			cnt2++;
			temp[idx] = '[';
			idx++;
		}
		else if (str[i] == ')') {
			cnt1--;
			temp[idx - 1] -= '(';
			if (temp[idx - 1] != 0) {
				return 0;
			}
			idx--;
		}
		else if (str[i] == ']') {
			cnt2--;
			temp[idx - 1] -= '[';
			if (temp[idx - 1] != 0) {
				return 0;
			}
			idx--;
		}
	}
	if (cnt1 == 0 && cnt2 == 0) {
		return 1;
	}
	return 0;
}

int main() {
	char str[101];
	char* pstr = &str;
	while (1) {
		fgets(str, 102, stdin);
		if (str[0] == '.') {
			return 0;
		}
		if (func(pstr)) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}
