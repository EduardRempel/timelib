/**
 * timelib
 *
 * library for time operations
 **/
#include <stdio.h>
#include <stdlib.h>

/** \brief
 *
 * \param year int
 * \return int
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

/** \brief
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

/** \brief
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

/** \brief
 *
 * \param day int*
 * \param month int*
 * \param year int*
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

/** \brief
 *
 * \param day int
 * \param month int
 * \param year int
 * \return int
 *
 */
int day_of_the_year(int day, int month, int year)
{

    if(!exist_date(day, month, year))
    {
        return -1;
    }

    int tagDesJahres = 0;
    for(int i = 1; i < month  ; i++){
        tagDesJahres += get_days_for_month(i, year);
    }

    tagDesJahres += day;
    return tagDesJahres;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2020));
    printf("Tag des Jahres: %i\n", day_of_the_year(1, 3, 1996));
	int day, month, year;
	while(1)
	{
		input_date(&day, &month, &year);
		printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));
	}

    return 0;
}
