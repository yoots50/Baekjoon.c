#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func1(int* arr, int length) {
	double sum = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	return round(sum / length);
}

int compare(const void* a, const void* b) {
	int A = *(int*)a;
	int B = *(int*)b;
	if (A > B) {
		return 1;
	}
	else if (A == B) {
		return 0;
	}
	else {
		return -1;
	}
}

int func2(int* arr, int length) {
	qsort(arr, length, sizeof(arr[0]), compare);
	return arr[(length - 1) / 2];
}

int func3(int* arr, int length) {
	int temp[8001] = { 0, };
	for (int i = 0; i < length; i++) {
		temp[arr[i] + 4000]++;
	}
	int max = 0;
	int idx = 0;
	for (int i = 0; i < 8001; i++) {
		if (max < temp[i]) {
			max = temp[i];
			idx = i;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 8001; i++) {
		if (max == temp[i]) {
			if (cnt) {
				return i - 4000;
			}
			cnt++;
		}
	}
	return idx - 4000;
}

int func4(int* arr, int length) {
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < length; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return max - min;
}

int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n", func1(arr, N));
	printf("%d\n", func2(arr, N));
	printf("%d\n", func3(arr, N));
	printf("%d", func4(arr, N));
}