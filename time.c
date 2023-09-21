#include <stdio.h>
#include <time.h>



/* Convert secondes to days */
int to_days(time_t s)
{
    return (int)(s / (24 * 60 * 60)) + 1;
}

/* Set start time at 00:00 hours, Jan 1, 1970 UTC */
void set_start_date(struct tm date[])
{
    date[0].tm_mon -= 1; // Month is 0-based (0 = January, 1 =>
    date[0].tm_year -= 1900; // Years since 1900
    // Set the remaining fields of the struct tm
    date[0].tm_hour = 0;
    date[0].tm_min = 0;
    date[0].tm_sec = 0;
    date[0].tm_wday = 0;
    date[0].tm_yday = 0;
    date[0].tm_isdst = 0;
}


int main(){
    time_t currentTime;
    time_t seconds;
    struct tm date[1];

    time(&currentTime);
    printf("%ld secondes since 00:00 hours, Jan 1, 1970 UTC\n", currentTime);

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &date[0].tm_mday, &date[0].tm_mon, &date[0].tm_year);
    printf("The time selected is %d/%d/%d \n", date[0].tm_mday, date[0].tm_mon, date[0].tm_year);

    set_start_date(&date[0]);

    seconds = mktime(&date[0]);
    printf("The time selected in seconds is %ld seconds\n", seconds);

    time_t diff_between = difftime(seconds, currentTime);
    printf("the diffrence between now and the date selected is %ld seconds. \n", diff_between);
    printf("in %d days. \n", to_days(diff_between));

    return 0;
}