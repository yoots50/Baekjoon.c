#include <math.h>
int main() {
    int i, n, x1, y1, r1, x2, y2, r2, d;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
        d = r1 - r2;
        if (d < 0) {
            d *= -1;
        }
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) {
                printf("%d\n", -1);
            }
            else {
                printf("%d\n", 0);
            }
        }
        else {
            if (d < sqrt(pow((x1-x2),2)+pow((y1-y2),2)) && sqrt(pow((x1-x2),2)+pow((y1-y2),2))<r1+r2) {
                printf("%d\n", 2);
            }
            else if (sqrt(pow((x1-x2),2)+pow((y1-y2),2))==r1+r2 || sqrt(pow((x1-x2),2)+pow((y1-y2),2)) == d) {
                printf("%d\n", 1);
            }
            else if (sqrt(pow((x1-x2),2)+pow((y1-y2),2))>r1+r2 || sqrt(pow((x1-x2),2)+pow((y1-y2),2)) < d) {
                printf("%d\n", 0);
            }
        }
    }
    return 0;
}