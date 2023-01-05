#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	int* stack = (int*)malloc(sizeof(int) * N);
	char push[] = "push";
	char pop[] = "pop";
	char size[] = "size";
	char empty[] = "empty";
	char top[] = "top";
	char cmd[6];
	int idx = 0;
	int num;
	for (int i = 0; i < N; i++) {
		scanf("%s", &cmd);
		if (!strcmp(push, cmd)) {
			scanf("%d", &num);
			stack[idx] = num;
			idx++;
		}
		else if (!strcmp(pop, cmd)) {
			if (!idx) {
				printf("-1\n");
			}
			else {
				printf("%d\n", stack[idx - 1]);
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
		else {
			if (!idx) {
				printf("-1\n");
			}
			else {
				printf("%d\n", stack[idx - 1]);
			}
		}
	}
}