#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arrShiftLeft(int* arr, int length) {
	for (int i = 0; i < length - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[length - 1] = '\0';
}

int main() {
	int N;
	scanf("%d", &N);
	int* queue = (int*)malloc(sizeof(int) * N);
	char push[] = "push";
	char pop[] = "pop";
	char size[] = "size";
	char empty[] = "empty";
	char front[] = "front";
	char back[] = "back";
	char cmd[6];
	int idx = 0;
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%s", &cmd);
		if (!strcmp(push, cmd)) {
			scanf("%d", &num);
			queue[idx] = num;
			idx++;
		}
		else if (!strcmp(pop, cmd)) {
			if (!idx) {
				printf("-1\n");
			}
			else {
				printf("%d\n", queue[0]);
				arrShiftLeft(queue, idx);
				idx--;
			}
		}
		else if (!strcmp(size, cmd)) {
			printf("%d\n", idx);
		}
		else if (!strcmp(empty, cmd)) {
			if (!idx) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (!strcmp(front, cmd)) {
			if (!idx) {
				printf("-1\n");
			}
			else {
				printf("%d\n", queue[0]);
			}
		}
		else {
			if (!idx) {
				printf("-1\n");
			}
			else {
				printf("%d\n", queue[idx - 1]);
			}
		}
	}
}