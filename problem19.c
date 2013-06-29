#include <stdio.h>

int getDaysOfMonth(int month, int year) {
	if(month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
		return 31;

	if(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;

	if(year % 4 == 0) return 29;

	return 28;
}


int main ( ) {
	int day, month, year, total;

	day = 2;
	month = 1;
	year = 1901;
	total = 0;

	while(year < 2001) {
		while(month < 13) {
			if(day%7 == 0) total++;
			day = day + getDaysOfMonth(month, year);
			month++;
		}
		month = 1;
		year++;
	}

	printf("%d", total);

	return 0;
}
