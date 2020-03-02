/**
 * timelib
 *
 * library for time operations
 **/
#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/** \brief Checks if a given year is a leap year
 *
 * \param year int
 * \return int      0 if false, 1 if true
 *
 */
int is_leapyear(int year)
{
    if(year < 1582)
    {
        return -1;
    }

    return (year%4 == 0 && year%100) != 0 || year%400 == 0;
}

/** \brief returns the number of days for a given month and year
 *
 * \param month int
 * \param year int
 * \return int
 *
 */
int get_days_for_month(int month, int year)
{
    if(month > 12 || month < 1)
    {
        return -1;
    }

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(is_leapyear(year))
	{
        days[1] = 29;
    } else {
        days[1] = 28;
    }

    return days[month - 1];
}

/** \brief checks if a date is valide
 *
 * \param day int
 * \param month int
 * \param year int
 * \return int
 *
 */
int exist_date(int day, int month, int year)
{
  return !(day < 1 || day > get_days_for_month(month, year) || year < 1582 || year > 2400);
}

int exist_date_struct(struct date date)
{
    return !(date.day < 1 || date.day > get_days_for_month(date.month, date.year) || date.year < 1582 || date.year > 2400);
}



/** \brief reads values for day, month and year from a user
 *
 * \param day int*      output param
 * \param month int*    output param
 * \param year int*     output param
 * \return void
 *
 */
void input_date(int* day, int* month, int* year)
{
    do
	{
        *day = 0; *month = 0; *year = 0;

	    printf("Bitte Tag eingeben: ");
		scanf("%i", day);
		fflush(stdin);

		printf("Bitte Monat eingeben: ");
		scanf("%i", month);
		fflush(stdin);

		printf("Bitte Jahr eingeben: ");
		scanf("%i", year);
		fflush(stdin);

    }
    while(!exist_date(*day, *month, *year));
}

struct date input_date_struct()
{
     struct date date;

    do
	{
        date.day = 0; date.month = 0; date.year = 0;

	    printf("Bitte Tag eingeben: ");
		scanf("%i", &date.day);
		fflush(stdin);

		printf("Bitte Monat eingeben: ");
		scanf("%i", &date.month);
		fflush(stdin);

		printf("Bitte Jahr eingeben: ");
		scanf("%i", &date.year);
		fflush(stdin);

    }
    while(!exist_date_struct(date));

    return date;
};

/** \brief calculates and returns the day of the year for a given day, month and year
 *
 * \param day int
 * \param month int
 * \param year int
 * \return int
 *
 */
int day_of_the_year(struct date date)
{

    if(!exist_date(date.day, date.month, date.year))
    {
        return -1;
    }

    int day_of_the_year = 0;
    int i;
    for(i = 1; i < date.month  ; i++){
        day_of_the_year += get_days_for_month(i, date.year);
    }

    day_of_the_year += date.day;
    return day_of_the_year;
}
