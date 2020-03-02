#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date
{
    int day;
    int month;
    int year;
};


int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exist_date_struct(struct date date);
int exist_date(int day, int month, int year);
void input_date(int* day, int* month, int* year);
struct date input_date_struct();
int day_of_the_year(struct date date);



#endif // TIMELIB_H_INCLUDED
