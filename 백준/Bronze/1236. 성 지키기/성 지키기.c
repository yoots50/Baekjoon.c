#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	char** arr = (char**)malloc(sizeof(char*) * N);
	int rowCheck = 0;
	int colCheck = 0;
	int check = 1;
	for (int i = 0; i < N; i++) {
		arr[i] = (char*)malloc(sizeof(char) * M);
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j][i] == 'X') {
				check = 0;
			}
		}
		if (check) {
			rowCheck++;
		}
		check = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'X') {
				check = 0;
			}
		}
		if (check) {
			colCheck++;
		}
		check = 1;
	}
	int answer = rowCheck > colCheck ? rowCheck : colCheck;
	printf("%d", answer);
}