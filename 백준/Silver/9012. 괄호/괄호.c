#include <stdio.h>
#include <stdlib.h>

int func(char* str) {
	int cnt = 0;
	int idx = 0;
	while (str[idx]) {
		if (cnt == 0 && str[idx] == ')') {
			return 0;
		}
		else {
			if (str[idx] == '(') {
				cnt++;
			}
			else {
				cnt--;
			}
		}
		idx++;
	}
	if (cnt == 0) {
		return 1;
	}
	else {
		return 0;
	}
	idx = 0;
	cnt = 0;
}

int main() {
	int T;
	scanf("%d", &T);
	char str[51];
	
	for (int i = 0; i < T; i++) {
		scanf("%s", &str);
		if (func(&str)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}