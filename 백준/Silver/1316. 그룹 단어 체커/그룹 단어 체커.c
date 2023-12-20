#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	
    char input[101];
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int alpha[26];
        for (int i = 0; i < 26; i++) {
            alpha[i] = -1;
        }
        scanf("%s", input);
        
        int idx = 0;
        while (input[idx] != '\0') {
            if (alpha[input[idx] - 'a'] != -1 && alpha[input[idx] - 'a'] + 1 != idx) {
                cnt--;
                break;
            }
            alpha[input[idx] - 'a'] = idx;
            idx++;
        }
        cnt++;
    }
    
    printf("%d", cnt);
}