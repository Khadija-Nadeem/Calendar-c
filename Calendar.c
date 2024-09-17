#include <stdio.h>

#define TRUE 1 
#define FALSE 0 

// Days in each month (index 0 unused)
int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Month names (index 0 unused)
char *months[] = {
    " ", 
    "\nJanuary", 
    "\nFebruary", 
    "\nMarch", 
    "\nApril", 
    "\nMay", 
    "\nJune", 
    "\nJuly", 
    "\nAugust", 
    "\nSeptember", 
    "\nOctober", 
    "\nNovember", 
    "\nDecember"
};

// Get the year input from the user
int inputYear(void) {
    int year;
    printf("Enter a year (e.g. 2001): ");
    scanf("%d", &year);
    return year;
}

// Determine if it's a leap year and adjust February days
int determineLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[2] = 29;
        return TRUE;
    } else {
        daysInMonth[2] = 28;
        return FALSE;
    }
}

// Calculate the day code for January 1st of the given year
int determineDayCode(int year) {
    int dayCode, d1, d2, d3;
    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    dayCode = (year + d1 - d2 + d3) % 7;
    return dayCode;
}

// Print the weekday headers
void printMonthHeader() {
    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
}

// Print the calendar for each month
void printCalendar(int year, int dayCode) {
    int month, day;
    for (month = 1; month <= 12; month++) {
        printf("\n\n%10s\n", months[month]); // Print month name
        printMonthHeader(); 

        // Print leading spaces for the first day of the month
        for (day = 0; day < dayCode; day++) {
            printf("     ");
        }

        // Print the dates for the month
        for (day = 1; day <= daysInMonth[month]; day++) {
            printf("%3d  ", day); // Print each date
            if ((day + dayCode) % 7 == 0) {
                printf("\n"); // New line after Saturday
            }
        }
        printf("\n");

        // Calculate dayCode for the next month
        dayCode = (dayCode + daysInMonth[month]) % 7;
    }
}

int main(void) {
    int year, dayCode;
    year = inputYear(); 
    dayCode = determineDayCode(year); 
    determineLeapYear(year); 
    printCalendar(year, dayCode); 
    return 0;
}