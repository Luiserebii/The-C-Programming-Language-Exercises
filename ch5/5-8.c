#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);

int main() {
    int doy = day_of_year(2019, 10, 10);
    printf("day of year 10/10/2019: %d\n", doy);
    int month, year;
    month_day(2019, doy, &month, &year);
    printf("day and month of day %d of 2019: %d | %d\n", doy, month, year);
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int leap;
    if(month > 12 || month < 0) {
        printf("month passed is invalid");
        return -1;
    }
    if(day > 31 || day < 0) {
        printf("day passed is invalid");
        return -1;
    }
    //Determine whether leap year or not
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for(int i = 1; i < month; ++i) {
        day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday) {
    int i, leap;
    if(yearday > 366) {
        printf("yearday passed in invalid");
        return;
    }
    //Determine whether leap year or not
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for(i = 1; yearday > daytab[leap][i]; ++i) {    
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}
