#include "timelib.h"


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
