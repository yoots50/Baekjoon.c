#include <stdio.h>

int main() {
  int min = 2000;
  int input;
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &input);
    if (min > input) {
      min = input;
    }
  }
  sum += min;
  min = 2000;
  for (int i = 0; i < 2; i++) {
    scanf("%d", &input);
    if (min > input) {
      min = input;
    }
  }
  sum += min;

  printf("%d", sum - 50);
}