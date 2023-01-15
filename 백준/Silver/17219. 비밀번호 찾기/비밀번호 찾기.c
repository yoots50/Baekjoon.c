#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dictionary {
	long long int address;
	char passwd[21];
}dict;

int qsort_compare(const void* a, const void* b) {
	long long int A = *(long long int*)a;
	long long int B = *(long long int*)b;
	if (A < B) {
		return -1;
	}
	return A > B;
}

long long int hash(const char* str) {
	int len = strlen(str);
	long long int temp;
	long long int answer = 0;
	for (int i = 0; i < len; i++) {
		temp = str[i] - 'a' + 1;
		for (int j = 0; j < i; j++) {
			temp = temp * 101;
			temp -= (long long int)(temp / 1234567891) * 1234567891;
		}
		answer += temp;
	}
	return answer;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	dict* arr = (dict*)malloc(sizeof(dict) * N);
	char input[21];
	for (int i = 0; i < N; i++) {
		scanf("%s%s", &input, &arr[i].passwd);
		arr[i].address = hash(input);
	}
	qsort(arr, N, sizeof(arr[0]), qsort_compare);
	int start, end, mid;
	long long int input_hash;
	for (int i = 0; i < M; i++) {
		scanf("%s", &input);
		start = -1;
		end = N;
		input_hash = hash(input);
		while (end - start >= 1) {
			mid = (start + end) / 2;
			if (arr[mid].address == input_hash) {
				printf("%s\n", arr[mid].passwd);
				break;
			}
			else {
				if (arr[mid].address < input_hash) {
					start = mid;
				}
				else {
					end = mid;
				}
			}
		}
	}
}