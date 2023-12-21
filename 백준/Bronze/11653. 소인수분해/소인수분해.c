#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    int* primes = (int*)malloc(sizeof(int) * (N + 1));
    for (int i = 2; i < N + 1; i++) {
        primes[i] = i;
    }
    
    int idx;
    for (int i = 2; i < N + 1; i++) {
        if (primes[i] != 0) {
            idx = i * 2;
            while (idx < N) {
                primes[idx] = 0;
                idx += i;
            }
        }
    }
    
    int tmp = N;
    while (tmp != 1) {
        for (int i = 2; i < N + 1; i++) {
            if (primes[i] != 0 && tmp % primes[i] == 0) {
                printf("%d\n", primes[i]);
                tmp /= primes[i];
                break;
            }
        }
    }
}