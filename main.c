#include "timelib.h"


int main()
{
    struct date test_date;
    test_date.day = 31;
    test_date.month = 12;
    test_date.year = 2018;
    printf("Tag des Jahres: %i\n", day_of_the_year(test_date));

    test_date.day = 31;
    test_date.month = 12;
    test_date.year = 2020;
    printf("Tag des Jahres: %i\n", day_of_the_year(test_date));

    test_date.day = 1;
    test_date.month = 3;
    test_date.year = 1996;
    printf("Tag des Jahres: %i\n", day_of_the_year(test_date));
	int day, month, year;
	while(1)
	{
		test_date = input_date_struct();
		printf("Tag des Jahres: %i\n", day_of_the_year(test_date));
	}

    return 0;
}
