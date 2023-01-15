#include <stdio.h>
#include <stdlib.h>

int binary_search(int* arr, int len, int v) {
	if (len <= 0) {
		return -1;
	}
	int start = -1;
	int end = len;
	int mid;
	while (end - start > 1) {
		mid = (start + end) / 2;
		if (arr[mid] == v) {
			return mid;
		}
		if (arr[mid] < v) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	return -1;
}

int func(const int* arr, const int N, char* Newarr) {
	int* stack = (int*)malloc(sizeof(int) * N);
	int stackidx = 0;
	int push = 1;
	int Newarridx = 0;
	for (int i = 0; i < N; i++) {
		if (binary_search(stack, stackidx + 1, arr[i]) == -1) {
			for (int j = push; j <= arr[i]; j++) {
				stack[stackidx++] = j;
				push++;
				Newarr[Newarridx++] = '+';
			}
			stack[stackidx--] = '\0';
			Newarr[Newarridx++] = '-';
		}
		else {
			if (stack[stackidx - 1] != arr[i]) {
				return 0;
			}
			stack[stackidx--] = '\0';
			Newarr[Newarridx++] = '-';
		}
	}
	return 1;
}

int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	char* Newarr = (char*)malloc(sizeof(char) * N * 2);
	if (func(arr, N, Newarr)) {
		int idx = 0;
		while (Newarr[idx] == '+' || Newarr[idx] == '-') {
			printf("%c\n", Newarr[idx++]);
		}
	}
	else {
		printf("NO");
	}
}