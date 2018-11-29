#include <stdio.h>
#include <stdlib.h>

void month_day(int year, int yearday, int *pmonth, int *pday);
int day_of_year(int year, int month, int day);

int main()
{
	int pmonth;
	int pday;
	printf("Day of year: %d\n", day_of_year(1995, 2, 29));
	printf("Day of year: %d\n", day_of_year(1996, 2, 29));
	month_day(2004, 366, &pmonth, &pday);
	printf("Month %d and Day %d set.\n", pmonth, pday);
	month_day(2004, 368, &pmonth, &pday);
	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int i, leap;

	if (month > 12 || month < 1){ /* Check that month is 1-12 */
		printf("Error, month invalid\n");
		return -1;
	}

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	if (day > (*(daytab+leap))[month]){ /* Check that day isn't out of bounds for month */
		printf("Error, day %d out of bounds for month %d in %d\n", day, month, year);
		return -1;
	}
	for(i=1; i < month; i++) 
		day += (*(daytab+leap))[i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	if ((leap && (yearday > 366 || yearday < 1)) || \
	(!leap && (yearday > 365 || yearday < 1))){
		/* Check that yearday is valid for given year */
		printf("Error, day %d not valid for year %d\n", yearday, year);
		return;
	}
	for(i=1; yearday > (*(daytab+leap))[i]; i++) 
		yearday -= (*(daytab+leap))[i];
	*pmonth = i;
	*pday = yearday;
}