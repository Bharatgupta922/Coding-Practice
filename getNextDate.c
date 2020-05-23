#include <stdio.h>
#include <math.h>
struct date
{
    int day, month, year;
};
int isLeap(int year) { return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)); }
int ismonthThirtyOne(int month) { return month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12; }
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        struct date ip;
        scanf("%d%d%d", &ip.day, &ip.month, &ip.year);
        if (isLeap(ip.year) && ip.month == 2)
            ip.day == 29 ? ip.day = 1, ip.month++ : ip.day++;
        else if (ip.month == 2)
            ip.day == 28 ? ip.day = 1, ip.month++ : ip.day++;
        else if (ip.day == 31 && ip.month == 12)
            ip.year++, ip.day = 1, ip.month = 1;
        else if (ismonthThirtyOne(ip.month))
            ip.day == 31 ? ip.month++, ip.day = 1 : ip.day++;
        else
            ip.day == 30 ? ip.month++, ip.day = 1 : ip.day++;
        ((int)log10(ip.day) + 1) == 2 ? printf("%d-", ip.day) : printf("0%d-", ip.day);
        ((int)log10(ip.month) + 1) == 2 ? printf("%d-", ip.month) : printf("0%d-", ip.month);
        printf("%d\n", ip.year);
    }
    getch();
    return 0;
}
