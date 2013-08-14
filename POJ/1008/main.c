#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * MonthsOfHaab[19] = {
	"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin",
	"mol", "chen", "yax", "zac", "ceh", "mac", "kankin",
	"muan", "pax", "koyab", "cumhu", "uayet" };
char* DayNamesOfTzolkin[20] = { 
	"imix", "ik", "akbal", "kan", "chicchan", "cimi",
	"manik", "lamat", "muluk", "ok", "chuen", "eb",
	"ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};
int TotalDaysInTzolkin = 13 * 20;
int ParseHaab(int day, char* month, int year)
{
	int m = 0;
	int totals = year * 365 + day;
	while (strcmp(month,MonthsOfHaab[m])!=0)
	{
		m++;
		totals += 20;
	}
	return totals;
}
void ToTzolkin(int days)
{
	int year = days / TotalDaysInTzolkin;
	int day = days % (13 * 20);
	int num = day % 13;
	int str = day% 20;
	printf("%d %s %d\n", num+1, DayNamesOfTzolkin[str], year);
}
int main()
{
	int n, i;
	int* days;
	scanf("%d", &n);
	printf("%d\n", n);
	for (i = 0; i < n; i++)
	{
		int d;
		char m[10];
		int y;
		int days;
		scanf("%d. %s %d", &d, m, &y);
		days=ParseHaab(d, m, y);
		ToTzolkin(days);
	}
	return 0;
}