#include <stdio.h>
#include <string.h>
#define SET_LEN 22

int set[SET_LEN] = { 0, };

void setAdd(int idx) {
	if (set[idx] == 0) {
		set[idx] = 1;
	}
}

void setRemove(int idx) {
	if (set[idx] == 1) {
		set[idx] = 0;
	}
}

void setCheck(int idx) {
	if (set[idx] == 1) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}

void setToggle(int idx) {
	if (set[idx] == 1) {
		set[idx] = 0;
	}
	else {
		set[idx] = 1;
	}
}

void setAll() {
	for (int i = 0; i < SET_LEN - 1; i++) {
		set[i] = 1;
	}
}

void setEmpty() {
	for (int i = 0; i < SET_LEN - 1; i++) {
		set[i] = 0;
	}
}

int main() {
	int M;
	scanf("%d", &M);

	char add[] = "add";
	char remove[] = "remove";
	char check[] = "check";
	char toggle[] = "toggle";
	char all[] = "all";
	char empty[] = "empty";

	char cmd[8];
	int arg;

	for (int i = 0; i < M; i++) {
		
		scanf("%s", &cmd);

		if (!strcmp(add, cmd)) {
			scanf("%d", &arg);
			setAdd(arg);
			continue;
		}

		if (!strcmp(remove, cmd)) {
			scanf("%d", &arg);
			setRemove(arg);
			continue;
		}

		if (!strcmp(check, cmd)) {
			scanf("%d", &arg);
			setCheck(arg);
			continue;
		}

		if (!strcmp(toggle, cmd)) {
			scanf("%d", &arg);
			setToggle(arg);
			continue;
		}

		if (!strcmp(all, cmd)) {
			setAll();
			continue;
		}

		if (!strcmp(empty, cmd)) {
			setEmpty();
			continue;
		}
	}
}