/**
*
* Solution to course project # 10
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Dimitar Nikolaev Tankov
* @idnumber 2MI0600229
* @compiler GCC
*
* <header file with constants>
*
*/

const char* EVENTS_FILE_NAME = "events.txt";
const char* TEMP_FILE_NAME = "appending_events.txt";
const char* SUN_MON_FILE_NAME = "sunday_or_monday.txt";

const int daysInAWeek = 7;
const int numberOfMonths = 12;
const int daysInANormalYear = 365;
const int daysInALeapYear = 366;

const char* monthArray[12] = {"January", "February", "March", "April", "May", "June", "July",
                              "August", "September", "October", "November", "December"};

const char* monthRepresentation[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                                       "Aug", "Sep", "Oct", "Nov", "Dec"};

const char* dayOfTheWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

const char* dayOfTheWeekRepresentations[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

const char* dayOfTheWeekShortenedSundayStart[7] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
const char* dayOfTheWeekShortenedMondayStart[7] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};

const int lengthOfTextInFirstLine[12] = {12, 13, 10, 10, 8, 9, 9, 11, 14, 12, 13, 13};

const int numberOfDaysInAMonthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int numberOfDaysInAMonthArrayLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
