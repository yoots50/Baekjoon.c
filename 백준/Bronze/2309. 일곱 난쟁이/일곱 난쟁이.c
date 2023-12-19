#include <stdio.h>
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
    int arr[9];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    qsort(arr, 9, sizeof(int), compare);
    
    int fake1, fake2;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            fake1 = i;
            fake2 = j;
            
            if (sum - arr[fake1] - arr[fake2] == 100) {
                for (int i = 0; i < 9; i++) {
                    if (i != fake1 && i != fake2) {
                        printf("%d\n", arr[i]);
                    }
                }
                return 0;
            }
        }
    }
}