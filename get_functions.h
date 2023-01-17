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
* <header file with functions that get information from input>
*
*/

int getMonthNumPartial(const char* inputString){
    char monthNum[3] = {};
    int result = 0;

    if(strlen(inputString) == 6){
        strncpy(monthNum, inputString, 1);
    }else{
        strncpy(monthNum, inputString, 2);
    }

    result = std::stoi(monthNum);

    return result - 1;
}

int getYearPartial(const char* inputString){
    char year[5] = {};
    int result = 0;

    if(strlen(inputString) == 6){
        strcpy(year, inputString + 2);
    }else{
        strcpy(year, inputString + 3);
    }

    result = std::stoi(year);

    return result;
}

int getDayFull(const char* inputString){
    char day[3] = {};
    int result = 0;

    if(strlen(inputString) == 10){
        strncpy(day, inputString, 2);
    }
    if(strlen(inputString) == 9){

        if(*(inputString + 2) == '/'){
            strncpy(day, inputString, 2);
        }
        if(*(inputString + 1) == '/'){
            strncpy(day, inputString, 1);
        }
    }
    if(strlen(inputString) == 8){
        strncpy(day, inputString, 1);
    }

    result = std::stoi(day);

    return result;
}

int getMonthNumFull(const char* inputString){
    char monthNum[3] = {};
    int result = 0;

    if(strlen(inputString) == 10){
        strncpy(monthNum, inputString + 3, 2);
    }
    if(strlen(inputString) == 9){

        if(*(inputString + 2) == '/'){
            strncpy(monthNum, inputString + 3, 1);
        }
        if(*(inputString + 1) == '/'){
            strncpy(monthNum, inputString + 2, 2);
        }
    }
    if(strlen(inputString) == 8){
        strncpy(monthNum, inputString + 2, 1);
    }

    result = std::stoi(monthNum);

    return result - 1;
}

int getYearFull(const char* inputString) {
    char year[5] = {};
    int result = 0;

    if(strlen(inputString) == 10){
        strcpy(year, inputString + 6);
    }
    if(strlen(inputString) == 9){
        strcpy(year, inputString + 5);
    }
    if(strlen(inputString) == 8){
        strcpy(year, inputString + 4);
    }

    result = std::stoi(year);

    return result;
}

int getNumberOfEventsPerDay(const int dayOfTheMonth, const int monthNum, const int year){

    int count = 0;

    std::string buffer;
    std::string date;
    char* dateChar;

    std::fstream reading;

    reading.open(EVENTS_FILE_NAME);

    if(reading.is_open()){

        while(getline(reading, buffer)){

            int positionOfDelimiter = buffer.find(':');
            date = buffer.substr(positionOfDelimiter + 1);
            dateChar = &date[0];

            if (year == getYearFull(dateChar)) {
                if (dayOfTheMonth == getDayFull(dateChar) && monthNum == getMonthNumFull(dateChar)) {
                    count++;
                }
            }
        }
    }

    return count;
}

int getNumberOfDaysPerEvent(const char* name){

    std::string buffer;
    std::string temp;
    int result = 0;

    std::fstream reading;

    reading.open(EVENTS_FILE_NAME);

    if(reading.is_open()){

        while(getline(reading, buffer)){

            int positionOfDelimiter = buffer.find(':');
            temp = buffer.substr(0, positionOfDelimiter);

            if(name == temp){
                result++;
            }
        }
    }
    return result;
}