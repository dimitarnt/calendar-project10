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
* <header file with functions regarding the current day>
*
*/

void currentDayOfTheWeek(){
    time_t now = time(nullptr);
    const char* conversion = ctime(&now);

    for(int i = 0; i < daysInAWeek; ++i){
        if(strncmp(conversion, dayOfTheWeekRepresentations[i], 3) == 0){
            std::cout << dayOfTheWeek[i];
            break;
        }
    }
}

int currentDayOfTheMonth(){
    time_t now = time(nullptr);
    const char* conversion = ctime(&now);

    char dayOfTheMonth[3] = {};
    int result = 0;

    strncpy(dayOfTheMonth, conversion + 8, 2);

    result = std::stoi(dayOfTheMonth);

    return result;
}

void currentMonth(){
    time_t now = time(nullptr);
    const char* conversion = ctime(&now);

    for(int i = 0; i < numberOfMonths; ++i){
        if(strncmp(conversion + 4, monthRepresentation[i], 3) == 0){
            std::cout << monthArray[i];
            break;
        }
    }

}

int currentMonthNum(){
    time_t now = time(nullptr);
    const char* conversion = ctime(&now);

    for(int i = 0; i < numberOfMonths; ++i){
        if(strncmp(conversion + 4, monthRepresentation[i], 3) == 0){
            return i;
        }
    }

}

int currentYear(){
    time_t now = time(nullptr);
    const char* conversion = ctime(&now);

    char year[5] = {};
    int result = 0;

    strcpy(year, conversion + 20);

    result = std::stoi(year);

    return result;
}
