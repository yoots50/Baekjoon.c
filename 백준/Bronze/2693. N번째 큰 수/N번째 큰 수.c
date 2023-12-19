#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10

int compare(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;
    
    if (A < B) return -1;
    return A > B;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    int arr[MAX_LEN];
    int* ptr = arr;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            scanf("%d", &arr[j]);
        }        
        qsort(ptr, MAX_LEN, sizeof(int), compare);
        printf("%d\n", arr[MAX_LEN - 3]);
    }
}