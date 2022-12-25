#include <math.h>
int main() {
    int x1, y1, x2, y2, cx, cy, r, n, k, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d%d%d", &cx, &cy, &r);
            if ((sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2)) < r || 
                 sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2)) < r || 
                 sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2)) == 0 || 
                 sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2)) == 0)
                &&!
                (sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2)) < r && 
                 sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2)) < r)) {
                cnt += 1;
            }
        }
        printf("%d\n", cnt);
        cnt = 0;
    }
    return 0;
}