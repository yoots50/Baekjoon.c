#include <stdio.h>

int main() {
	int E, M, S;
	scanf("%d%d%d", &E, &M, &S);
	
	for (int i = 1; ; i++) {
	    if ((i % 15 == E || (i % 15 == 0 && E == 15)) && (i % 28 == M || (i % 28 == 0 && M == 28)) && (i % 19 == S || (i % 19 == 0 && S == 19))) {
	        printf("%d", i);
	        return 0;
	    }
	}
}