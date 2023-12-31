#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;
    
    if (A < B) {
        return -1;
    }
    return A > B;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("0");
        return 0;
    }
    
    int sum = 0;
    int f = (int)round((double)n * 15 / 100);
    
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), compare);
    
    for (int i = 0; i < n; i++) {
        if (f <= i && i < n - f) {
            sum += arr[i];
        }
    }
    printf("%d", (int)round((double)sum / (double)(n - f * 2)));
}