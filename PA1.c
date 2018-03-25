#include <stdio.h>
// These are the function prototypes
int dayOfWeek(int year);
int isLeapYear(int year);
int daysInMonth(int year, int month);
void printCalendar(int year, int month);
int printMonth(int year, int month, int startingDay);
int printMonthName(int year, int month);

/**
  * this function obtains the user input and executes the code
  * @return if the user inputs an invalid year the error message will be printed and will return -1.
Else the program will return a 0 if the program runs correctly
*/
int main() {
  int year; // this is used to store the value of what the user typed in
  printf("\t\t MONTHLY CALENDAR \t\t\n\n");
  printf("Please enter year for this calendar:- "); scanf("%d", &year);

  if (year <= 0) {
    printf("\nThat year does not exist.\n\n");
    return -1; // error case
    //main();
  }
  else {
    printCalendar(year, dayOfWeek(year));
    printf("\n");
    return 0;
  }
}

/**
  * this function will calculate which day of the week that the first day of the year (January 1st) will
be on and it will return the integer value the day of the week that the first day of the year lies on. (Sun = 0 ... Sat = 7)
  * @param year: the year to check for (ex: 2018)
  * @return the integer value of the day of the week that the 1st day of the inputed year (Jan 1) lies on. (ex: Sunday = 0)
*/
int dayOfWeek(int year) {
  int dayOfWeek; // is used to store the integer value of the day of week that the starting day of the inputed year lies on, where Sunday = 0

  // the calculation to determine the day of the week that the starting day of the inputed year lies on
  dayOfWeek = (( ( (year-1) + ( (year-1) / 4) ) - ( (year-1) / 100 ) + ( (year - 1) / 400 ) + 1) % 7);
  return dayOfWeek;
}

/**
  * this function will test to see if the inputed year fits the conditions that determines if the year is a leap year or not.
If the inputed year it will return a value of 1, which would represent a true case and if the year is not a leap year, the function
will return a 0 (0 = false).
  * @param year: the year that is checked for (ex: 2018)
  * @return the value of result. Result would be equaled to 0 if false or 1 if true
*/
int isLeapYear(int year) {
  int result; // this will hold the result of if the year is a leap year or not

  // the conditions that determines if the inputed year is a leap year
  if ( ((year % 400 == 0) || (year % 100 != 0)) && (year % 4 == 0)) {
    result = 1; // 1 represents a true case
  }
  else {
    result = 0; // 0 represents a false case
  }

  return result;
}

/**
  * this function will determine the number of days in the inputed month while also considering if the inputed year is a leap year
  * @param year : the year to check if it is a leap year (ex: 2018)
  * @param month : the month that is being checked (ex: January == 1)
  * @return will return the number of days in the inputed month as long as the month is a valid month (in between 1 and 12).
If the inputed month is not valid, it will return an error message that says the month is invalid and a -1. (ex: "Invalid Month" -1 [if not valid])
*/
int daysInMonth(int year, int month) {
  int numOfDays;  // stores the number of days in the inputed month

  switch(month) {
    // the months with 31 days
    case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 : numOfDays = 31;
    break;
    case 2 :
      /*
      tests to see if the year year is a leap year to determine the number of days in February. If function returns a 0 it would indicate that
      the year is not a leap year, but if it returns a 1 it would be a leap year
      */
      if (isLeapYear(year)) {
        numOfDays = 29;
      }
      else {
        numOfDays = 28;
      }
    break;
    // the months with 30 days
    case 4 : case 6 : case 9 : case 11 : numOfDays = 30;
    break;

    default : printf("\n Invalid Month \n"); // this is for the case where the inputed month value is not within the range of 1 to 12
    numOfDays = -1; //error case
    break;
  }

  return numOfDays;
}

/**
  * this function will print out the 12 months in a calendar format
  * @param year: the year that the calendar is for
  * @param startingDay: the int value of the day of the week that the month will start on (Sunday = 0, Monday = 1, etc)
  * @return the printed 12 months in calendar format
*/
void printCalendar(int year, int startingDay) {
  printf("\n***     CALENDAR for %d     ***\n", year);
  int month; // this is used to decide which month will be printed, with January = 1

  /*
  This for-loop loops is in charge of printing out the months 12 times. Within each iteration it prints out the month in a calendar format and
  it stores the starting day of the day of the week. By storing the starting day it can correctly position the starting date of the next month.
  */
  // pre-condition: month is set to the value of 1 and the year is set to the year that is printed out
  for (month = 1; month <= 12; month++) {
    // Loop Invarient: at this point all the months from 1 to (month - 1) have been printed out
    startingDay = printMonth(year, month, startingDay);
    // Loop Invarient: at this point the startingDay is equaled to most recently printed day of the week in the current month
  }
  // post-condition: the month is at the value of 12
  printf("\n");

}

/**
   * this function will print of the month in calendar format
   * @param year : the year that the calendar is for
   * @param month : the integer value that corresponds to the month that will be printed
   * @param startingDay : the integer value of the day of the week that the month will start on (Sunday = 0, Monday = 1, etc)
   * @return the integer value of the day of the week that the next month will start on
**/
int printMonth(int year, int month, int startingDay) {

  // prints out the name of the month and also stores the number of days in the inputed
  // month in numOfDaysInMonth. This variable will be used in the 2nd for-loop within this function
  int numOfDaysInMonth = printMonthName(year, month);
  printf("\n");

  /*
    this for-loop is to position the starting date at then correct position (day of the week). It does this by having 'indent' start at 0
    and as long as it is less than the value of the startingDay it will print a blank space with a length of 5 and will increase 'indent' by 1.
    This is to make sure that the printed month will follow the calendar format.
  */
  // pre-condition: indent is at 0 and the startingDay is set to a value
  for(int indent = 0; indent < startingDay; indent++) {
    printf("     "); // properly formats the starting date to the correct position
    // Loop Invarient: at this point the number of spaces printed is approaching or equaled to the number of blanks required to reach the value of startingDay
  }
  // post-condition: indent is equaled to the value of the startingDay

  int date; // this is used to decide which date is printed, with it starting at 1

  /*
    this for-loop prints out the dates in the month. For each iteration in the loop it will print out the current date value and increase
    the startingDay by 1. It will then check to see if the startingDay is greater than 6, and if so it will reset the value of the startingDay
    to 0 and go to the next line. The purpose of having this if statement is that once the startingDay reaches Saturday (Sat = 6), it will go
    on to the next line and print out the date under Sunday (Sun = 0). This is so that the printed month will follow the calendar format.
  */
  // pre-condition: the numOfDaysInMonth and startingDay must be set to a value and the date is set to 1
  for(date = 1; date <= numOfDaysInMonth; date++) {
    printf("%5d", date);
    startingDay++;
    if (startingDay > 6) {  // if the startingDay reaches Saturday (Saturday = 6) it will
                            // reset the startingDay to 0 and go to the next line
      startingDay = 0;

      printf("\n");
    }
    // Loop Invarient: at this point the date that is printed is not greater than the value of numOfDaysInMonth (number of days in the month)
  }
  // post-condition: the value of date is one greater to the value of numOfDaysInMonth and the startingDay is equaled to the value of the day of
  //                  the week that the next month will start at

  return startingDay;
}


/**
  * this function will print out the name of the month along with the year
  * @param year : the year that the calendar is for
  * @param month : the the integer value that corresponds to the month
  * @return the number of days in the inputed month
*/
int printMonthName(int year, int month) {
  switch(month) {
    case 1 : printf("\n%s %d\n\n", "January", year);
    break;
    case 2 : printf("\n\n%s %d\n\n", "February", year);
    break;
    case 3 : printf("\n\n%s %d\n\n", "March", year);
    break;
    case 4 : printf("\n\n%s %d\n\n", "April", year);
    break;
    case 5 : printf("\n\n%s %d\n\n", "May", year);
    break;
    case 6 : printf("\n\n%s %d\n\n", "June", year);
    break;
    case 7 : printf("\n\n%s %d\n\n", "July", year);
    break;
    case 8 : printf("\n\n%s %d\n\n", "August", year);
    break;
    case 9 : printf("\n\n%s %d\n\n", "September", year);
    break;
    case 10 : printf("\n\n%s %d\n\n", "October", year);
    break;
    case 11 : printf("\n\n%s %d\n\n", "November", year);
    break;
    case 12 : printf("\n\n%s %d\n\n", "December", year);
    break;

    default : printf("\n Invalid Month \n");  // this is for the case where the inputed month value is not within the range of 1 to 12 (not a valid month)
    break;
  }

  // correctly spaces out the days of the week
  printf("%5s %4s %4s %4s %4s %4s %4s", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");

  return daysInMonth(year, month);  // this function will return the number of days in the month
}
