#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int L;
	scanf("%d", &L);
	char* str = (char*)malloc(sizeof(char) * L);
	long long int* arr = (long long int*)malloc(sizeof(long long int) * L);
	scanf("%s", str);
	long long int sum = 0;
	for (int i = 0; i < L; i++) {
		str[i] -= 96;
		arr[i] = str[i];
		for (int j = 0; j < i; j++) {
			arr[i] *= 31;
			arr[i] -= (int)(arr[i] / 1234567891) * 1234567891;
		}
		sum += arr[i];
	}
	printf("%d", sum % 1234567891);
}