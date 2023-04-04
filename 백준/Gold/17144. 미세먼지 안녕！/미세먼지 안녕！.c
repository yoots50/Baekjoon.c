#include <stdio.h>
#include <stdlib.h>

int air(int** room, int R, int C) {
	int ret = 0;
	int isupper = 1;

	for (int i = 0; i < R; i++) {
		if (room[i][0] == -1) {
			if (isupper) {
				ret += room[i - 1][0];

				for (int row = i - 1; row > 0; row--) { // up to down
					room[row][0] = room[row - 1][0];
				}

				for (int col = 0; col < C - 1; col++) { // right to left
					room[0][col] = room[0][col + 1];
				}

				for (int row = 0; row <= i - 1; row++) { // down to up
					room[row][C - 1] = room[row + 1][C - 1];
				}

				for (int col = C - 1; col >= 2; col--) { // left to right
					room[i][col] = room[i][col - 1];
				}

				room[i][1] = 0;

				isupper = 0;
			}

			else {
				ret += room[i + 1][0];

				for (int row = i + 1; row < R - 1; row++) { // down to up
					room[row][0] = room[row + 1][0];
				}

				for (int col = 0; col < C - 1; col++) { // right to left
					room[R - 1][col] = room[R - 1][col + 1];
				}

				for (int row = R - 1; row > i; row--) { // up to down
					room[row][C - 1] = room[row - 1][C - 1];
				}

				for (int col = C - 1; col >= 2; col--) { // left to right
					room[i][col] = room[i][col - 1];
				}

				room[i][1] = 0;
				break;
			}
		}
	}

	return ret;
}

int check(int i, int j, int** room) {
	if (room[i][j] == -1) {
		return 1;
	}
	return 0;
}

void diffusion(int** room, int R, int C) {
	int** tmproom = (int**)malloc(sizeof(int*) * R);
	for (int i = 0; i < R; i++) {
		tmproom[i] = (int*)malloc(sizeof(int) * C);
		for (int j = 0; j < C; j++) {
			tmproom[i][j] = 0;
		}
	}

	int** tmpcnt = (int**)malloc(sizeof(int*) * R);
	for (int i = 0; i < R; i++) {
		tmpcnt[i] = (int*)malloc(sizeof(int) * C);
		for (int j = 0; j < C; j++) {
			tmpcnt[i][j] = 0;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0) {
				if (i > 0) {
					if (room[i - 1][j] != -1) {
						tmproom[i - 1][j] += room[i][j] / 5;
						tmpcnt[i][j]++;
					}
				}

				if (i < R - 1) {
					if (room[i + 1][j] != -1) {
						tmproom[i + 1][j] += room[i][j] / 5;
						tmpcnt[i][j]++;
					}
				}

				if (j > 0) {
					if (room[i][j - 1] != -1) {
						tmproom[i][j - 1] += room[i][j] / 5;
						tmpcnt[i][j]++;
					}
				}

				if (j < C - 1) {
					if (room[i][j + 1] != -1) {
						tmproom[i][j + 1] += room[i][j] / 5;
						tmpcnt[i][j]++;
					}
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0) {
				room[i][j] -= (room[i][j] / 5) * tmpcnt[i][j];
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (tmproom[i][j] > 0) {
				room[i][j] += tmproom[i][j];
			}
		}
	}

	free(tmpcnt);
	free(tmproom);
}

int leftover(int** room, int R, int C) {
	int ret = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0) {
				ret += room[i][j];
			}
		}
	}

	return ret;
}

void print_for_debug(int** room, int R, int C) {
	printf("-----------------------------\n");
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", room[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");
}

int main() {
	int R, C, T;
	scanf("%d%d%d", &R, &C, &T);

	int** room = (int**)malloc(sizeof(int*) * R);
	for (int i = 0; i < R; i++) {
		room[i] = (int*)malloc(sizeof(int) * C);
		for (int j = 0; j < C; j++) {
			scanf("%d", &room[i][j]);
		}
	}

	for (int i = 0; i < T; i++) {
		diffusion(room, R, C);
		air(room, R, C);
		//print_for_debug(room, R, C);
	}

	printf("%d", leftover(room, R, C));
}