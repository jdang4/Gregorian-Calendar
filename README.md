# Gregorian-Calendar

README for PA1.c by Jonathan Dang (1/22/2018)

My entire program was original.

Summary:
This program will ask for the user for a year and it will print out the 12 month calendar of that particular year (uses the Gregorian Calendar). In the process of printing out the
calendar it will first figure out if that year is a leap year and which day of the week the chosen year will start on.

How to Run it:
Before running the executable file of this program you must first compile it. You can compile the program by typing in: "gcc -Wall -o PA1 PA1.c" in the command line. If
it compiles, no warning signs should appear and you can go head and execute the program. When running the program it will first ask the user to type in a specific year
and it will only print out the calendar of that year if it is a valid year (anything greater than 0 and is a real number).

Problem Encountered:
During the progress of writing this program I really did not face any major problems. I did however ran into a problem where my daysInMonth function was outputting
the wrong number. The daysInMonth function would take in a year and calculate what day of the week January 1st of that year will be on. It would return the integer
value of the day of the week (Sunday = 0, Monday = 1, Tuesday = 2, and so on). The problem that I was having was that this function was not returning the correct value
and it took some debugging to realize that I did not correctly position my parentheses correctly. After fixing it, my program started to run correctly.

Main Functions:
My program has 3 main funtions. The 3 main functions are "printCalendar", "printMonth", and "printMonthName". The printCalendar function is in charge of printing out all
the 12 months in the year. It takes in 2 integers (year, startingDay) and it will call the "printMonth" function 12 times since there are 12 months in a year. The printMonth
function is in charge of printing out the month and also returning the integer value of the day of the week that the next month will start at. The printMonthName function would
take in an integer value that should correspond with a month and a year and it will use that integer value to print out the name of the month that it corresponds to along with
the year. It will also return the number of days in that inputed month by calling the helper function "dayOfWeek".

My main() function basically asks for the user to type in a year and depending on if that inputed year is a valid year or not (valid as in the year is greater than 0),
it will call the printCalendar function if the year is a valid year and will print out an error message if the year was not a valid one.

Helper Functions:
Along with the 3 main functions that were described above, my program also includes some helper functions which are "dayOfWeek", "leapYear", and "daysInMonth".

"dayOfWeek" Description:
The dayOfWeek function will take in a year and will substitute that year into the equation that will be used to determine what day of the week that the 1st day of the year
(January 1st) will lie on. The integer value that is returned from that equation should be represented by a day in a week so for instance if it were to return a 0, January 1st
of the inputed year will be on a Sunday and if it were to return 6, that date will be on Saturday. This function was called in the "main" function.

"isLeapYear" Description:
The leapYear function is used to determine if the inputed year is a leap year or not. Basically how this function works is that if the inputed year were to meet the
conditions of a leap year, the function will return a 1, which represents a true case, and if the inputed year does not meet the conditions, the function will
return a 0, which represents a false case. This function was called in the "daysInMonth" function.

      Side Note: The main reason I am using 1 and 0 over saying true or false is primarily due to C not having a boolean data type in the old versions, so it used
      integer values instead. How the integer values worked was that 0 would represent a false case and basically any non zero numbers would represent a true case.

"daysInMonth" Description:
The daysInMonth function is used to determine the number of days in the inputed month. The case for if the inputed month were to be 2 (February), this function deals with it
in a special way. It will test to see if the inputed year, that is a part of this function's parameter, is a leap year and if so it will set the number of days in that month
to 29. If not the year isn't a leap year it will set the number of days in that month to 28. It will test to see if the inputed year is a leap year by calling the
"isLeapYear" function. This function was called in the "printMonthName" function.

Loop Invarients:
  In printCalendar :
        Loop Invarient: Loop Invarient: at this point all the months from 1 to (month - 1) have been printed out 
        Loop Invarient: Loop Invarient: at this point the startingDay is equaled to most recently printed day of the week in the current month

  In printMonth :
        Loop Invarient: at this point the number of spaces printed is approaching or equaled to the number of blanks required to reach the value of startingDay
        Loop Invarient: at this point the date that is printed is not greater than the value of numOfDaysInMonth (number of days in the month)
