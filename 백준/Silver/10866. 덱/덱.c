#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arrShiftRight(int* arr, int length) {
	for (int i = length; i >= 1; i--) {
		arr[i] = arr[i - 1];
	}
}

void arrShiftLeft(int* arr, int length) {
	for (int i = 1; i <= length - 1; i++) {
		arr[i - 1] = arr[i];
	}
	arr[length - 1] = '\0';
}

int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	int length = 0;
	char push_front[] = "push_front";
	char push_back[] = "push_back";
	char pop_front[] = "pop_front";
	char pop_back[] = "pop_back";
	char size[] = "size";
	char empty[] = "empty";
	char front[] = "front";
	char back[] = "back";
	char cmd[11];
	int arg;
	for (int i = 0; i < N; i++) {
		scanf("%s", &cmd);
		if (!strcmp(cmd, push_front)) {
			scanf("%d", &arg);
			if (length) {
				arrShiftRight(arr, length);
			}
			arr[0] = arg;
			length++;
			continue;
		}
		if (!strcmp(cmd, push_back)) {
			scanf("%d", &arg);
			arr[length] = arg;
			length++;
			continue;
		}
		if (!strcmp(cmd, pop_front)) {
			if (length) {
				printf("%d\n", arr[0]);
				arrShiftLeft(arr, length);
				length--;
			}
			else {
				printf("-1\n");
			}
			continue;
		}
		if (!strcmp(cmd, pop_back)) {
			if (length) {
				printf("%d\n", arr[length - 1]);
				arr[length - 1] = '\0';
				length--;
			}
			else {
				printf("-1\n");
			}
			continue;
		}
		if (!strcmp(cmd, size)) {
			printf("%d\n", length);
			continue;
		}
		if (!strcmp(cmd, empty)) {
			if (length) {
				printf("0\n");
			}
			else {
				printf("1\n");
			}
			continue;
		}
		if (!strcmp(cmd, front)) {
			if (length) {
				printf("%d\n", arr[0]);
			}
			else {
				printf("-1\n");
			}
			continue;
		}
		if (!strcmp(cmd, back)) {
			if (length) {
				printf("%d\n", arr[length - 1]);
			}
			else {
				printf("-1\n");
			}
			continue;
		}
	}
}