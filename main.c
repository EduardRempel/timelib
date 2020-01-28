/**
 * timelib
 *
 * library for time operations
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 * Checks if a year is a leap year
 *
 **/
int istSchaltjahr(int jahr) {
    //Logik des Programms
    if (jahr%4 == 0){
        if (jahr%100 == 0){
            if (jahr%400 == 0){
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}


/**
 * Calculates the day of the year from a date
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    int monatstage[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //int day = 0, month = 0, year = 0;

    if(istSchaltjahr(year)){
        monatstage[1] = 29;
    } else {
        monatstage[1] = 28;
    }

    if(month > 12 || month < 1 || year < 1 || day < 1 || day > monatstage[month - 1])
    {
        return -1;
    }

    /*do {

		do{
			printf("Bitte geben Sie das heutigen Datum ein!\n");
			printf("Tag: ");
			scanf("%i", &tag);

			printf("Monat: ");
			scanf("%i", &monat);

			printf("Jahr: ");
			scanf("%i", &jahr);

		} while(monat > 12 || monat < 1 || jahr < 1 || tag < 1);


		if(istSchaltjahr(jahr)){
			monatstage[1] = 29;
		} else {
			monatstage[1] = 28;
		}
    } while(tag > monatstage[monat - 1]);*/

    int tagDesJahres = 0;
    for(int i = 0; i <= month -2 ; i++){
        tagDesJahres += monatstage[i];
    }

    tagDesJahres += day;

    //printf("Der Tag des Jahres ist %i\n", tagDesJahres);

    return tagDesJahres;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2020));
    return 0;
}
