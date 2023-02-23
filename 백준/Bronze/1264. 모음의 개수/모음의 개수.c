#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[300];
    char endChar = '#';
    int cnt = 0;
    while (1) {
        fgets(str, 300, stdin);
        if (str[0] == endChar) {
            break;
        }
        int len = strlen(str);
        char alp; 
        for (int i = 0; i < len; i++) {
            alp = tolower(str[i]);
            if (alp == 'a' || alp == 'e' || alp == 'i' || alp == 'o' || alp == 'u') {
                cnt++;
            }
        }
        printf("%d\n", cnt);
        cnt = 0;
    }
}