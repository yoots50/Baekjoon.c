#include <stdio.h>

int abs(int x) {
    return x > 0 ? x : -x;
}

int main()
{
    char ch;
    int sum = 0;
    int cnt = 0;
    int originx, originy;
    int nowx, nowy;
    while (cnt < 16) {
        ch = getchar();
        
        if (ch >= 'A') {
            nowx = cnt % 4;
            nowy = cnt / 4;
            
            originx = (ch - 'A') % 4;
            originy = (ch - 'A') / 4;
            
            sum += abs(originx - nowx) + abs(originy - nowy);
            cnt++;
        }
        
        if (ch == '.') {
            cnt++;
        }
    }
    
    printf("%d", sum);
}
