#include <stdio.h>

int main()
{
    char dayOfTheWeek[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int dayOfTheMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int month, day;
    scanf("%d%d", &month, &day);
    
    int sum = 0;
    for (int i = 0; i < month - 1; i++) {
        sum += dayOfTheMonth[i]; 
    }
    
    sum += day;
    
    printf("%s", dayOfTheWeek[sum % 7]);
}