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
* <header file with functions that validate input>
*
*/

bool validOptionInput(const char* option){

    if(strlen(option) != 1){
        return false;
    }

    if(!isdigit(*option)){
        return false;
    }

    if(std::stoi(option) < 1 || std::stoi(option) > 6){
        return false;
    }

    return true;
}

bool validCalendarAndScheduleInput(const char* inputString){

    if(strlen(inputString) != 6 && strlen(inputString) != 7){
        return false;
    }

    if(strlen(inputString) == 7){
        if(*(inputString + 2) != '/'){
            return false;
        }

        for(int i = 0; i < strlen(inputString); ++i){
            if(i != 2 && !isdigit(*(inputString + i))){
                return false;
            }
        }

        if(getMonthNumPartial(inputString) > 11){
            return false;
        }
    }

    if(strlen(inputString) == 6){
        if(*(inputString + 1) != '/'){
            return false;
        }

        for(int i = 0; i < strlen(inputString); ++i){
            if(i != 1 && !isdigit(*(inputString + i))){
                return false;
            }
        }
    }

    return true;
}

bool validEventNameInput(const char* name){

    if(strpbrk(name, ":") != nullptr){
        std::cout << "(Using the character ':' is not permitted)" << std::endl;
        return false;
    }

    return true;
}

bool validEventDateInput(const char* date){

    char day[3] = {};
    char monthNum[3] = {};
    char year[5] = {};

    if(strlen(date) != 10 && strlen(date) != 9 && strlen(date) != 8){
        return false;
    }

    if(strlen(date) == 10){
        if(*(date + 2) != '/' || *(date + 5) != '/'){
            return false;
        }

        for(int i = 0; i < strlen(date); ++i){
            if(i != 2 && i != 5 && !isdigit(*(date + i))){
                return false;
            }
        }

        strncpy(day, date, 2);
        strncpy(monthNum, date + 3, 2);
        strcpy(year, date + 6);

        if(std::stoi(year) % 400 == 0 || (std::stoi(year) % 4 == 0 && std::stoi(year) % 100 != 0)){
            if(std::stoi(day) < 1 || std::stoi(day) > numberOfDaysInAMonthArrayLeap[std::stoi(monthNum) - 1]){
                return false;
            }
        }else{
            if(std::stoi(day) < 1 || std::stoi(day) > numberOfDaysInAMonthArray[std::stoi(monthNum) - 1]){
                return false;
            }
        }

        if(std::stoi(monthNum) < 1 || std::stoi(monthNum) > numberOfMonths){
            return false;
        }

    }

    if(strlen(date) == 9){

        if(*(date + 4) != '/'){
            return false;
        }else{

            if(*(date + 1) != '/' && *(date + 2) != '/'){
                return false;
            }

            if(*(date + 1) == '/'){

                for(int i = 0; i < strlen(date); ++i){
                    if(i != 1 && i != 4 && !isdigit(*(date + i))){
                        return false;
                    }
                }

                strncpy(day, date, 1);
                strncpy(monthNum, date + 2, 2);
                strcpy(year, date + 5);

                if(std::stoi(year) % 400 == 0 || (std::stoi(year) % 4 == 0 && std::stoi(year) % 100 != 0)){
                    if(std::stoi(day) < 1 || std::stoi(day) > numberOfDaysInAMonthArrayLeap[std::stoi(monthNum) - 1]){
                        return false;
                    }
                }else{
                    if(std::stoi(day) < 1 || std::stoi(day) > numberOfDaysInAMonthArray[std::stoi(monthNum) - 1]){
                        return false;
                    }
                }

                if(std::stoi(monthNum) < 1 || std::stoi(monthNum) > numberOfMonths){
                    return false;
                }
            }

            if(*(date + 2) == '/'){

                for(int i = 0; i < strlen(date); ++i){
                    if(i != 2 && i != 4 && !isdigit(*(date + i))){
                        return false;
                    }
                }

                strncpy(day, date, 2);
                strncpy(monthNum, date + 3, 1);
                strcpy(year, date + 5);

                if(std::stoi(year) % 400 == 0 || (std::stoi(year) % 4 == 0 && std::stoi(year) % 100 != 0)){
                    if(std::stoi(day) < 1 || std::stoi(day) > numberOfDaysInAMonthArrayLeap[std::stoi(monthNum) - 1]){
                        return false;
                    }
                }else{
                    if(std::stoi(day) < 1 || std::stoi(day) > numberOfDaysInAMonthArray[std::stoi(monthNum) - 1]){
                        return false;
                    }
                }

                if(std::stoi(monthNum) < 1 || std::stoi(monthNum) > numberOfMonths){
                    return false;
                }
            }
        }

    }

    if(strlen(date) == 8){
        if(*(date + 1) != '/' && *(date + 3) != '/'){
            return false;
        }

        for(int i = 0; i < strlen(date); ++i){
            if(i != 1 && i != 3 && !isdigit(*(date + i))){
                return false;
            }
        }

        strncpy(day, date, 1);
        strncpy(monthNum, date + 2, 1);
        strcpy(year, date + 4);

        if(std::stoi(year) % 400 == 0 || (std::stoi(year) % 4 == 0 && std::stoi(year) % 100 != 0)){
            if(std::stoi(day) < 1 || std::stoi(day) > numberOfDaysInAMonthArrayLeap[std::stoi(monthNum) - 1]){
                return false;
            }
        }else{
            if(std::stoi(day) < 1 || std::stoi(day) > numberOfDaysInAMonthArray[std::stoi(monthNum) - 1]){
                return false;
            }
        }

        if(std::stoi(monthNum) < 1 || std::stoi(monthNum) > numberOfMonths){
            return false;
        }
    }

    return true;
}

bool validEventEndDateInput(const char* startDate, const char* endDate){

    char startDateDay[3] = {};
    char startDateMonthNum[3] = {};
    char startDateYear[5] = {};

    char endDateDay[3] = {};
    char endDateMonthNum[3] = {};
    char endDateYear[5] = {};

    if(strlen(startDate) != 10 && strlen(startDate) != 9 && strlen(startDate) != 8){
        return false;
    }
    if(strlen(endDate) != 10 && strlen(endDate) != 9 && strlen(endDate) != 8){
        return false;
    }

    if(strlen(startDate) == 10){

        strncpy(startDateDay, startDate, 2);
        strncpy(startDateMonthNum, startDate + 3, 2);
        strcpy(startDateYear, startDate + 6);
    }
    if(strlen(startDate) == 9){

        if(*(startDate + 1) == '/'){
            strncpy(startDateDay, startDate, 1);
            strncpy(startDateMonthNum, startDate + 2, 2);
            strcpy(startDateYear, startDate + 5);
        }

        if(*(startDate + 2) == '/'){
            strncpy(startDateDay, startDate, 2);
            strncpy(startDateMonthNum, startDate + 3, 1);
            strcpy(startDateYear, startDate + 5);
        }
    }
    if(strlen(startDate) == 8){
        strncpy(startDateDay, startDate, 1);
        strncpy(startDateMonthNum, startDate + 2, 1);
        strcpy(startDateYear, startDate + 4);
    }

    if(strlen(endDate) == 10){

        strncpy(endDateDay, endDate, 2);
        strncpy(endDateMonthNum, endDate + 3, 2);
        strcpy(endDateYear, endDate + 6);
    }
    if(strlen(endDate) == 9){

        if(*(endDate + 1) == '/'){
            strncpy(endDateDay, endDate, 1);
            strncpy(endDateMonthNum, endDate + 2, 2);
            strcpy(endDateYear, endDate + 5);
        }

        if(*(endDate + 2) == '/'){
            strncpy(endDateDay, endDate, 2);
            strncpy(endDateMonthNum, endDate + 3, 1);
            strcpy(endDateYear, endDate + 5);
        }
    }
    if(strlen(endDate) == 8){
        strncpy(endDateDay, endDate, 1);
        strncpy(endDateMonthNum, endDate + 2, 1);
        strcpy(endDateYear, endDate + 4);
    }

    if(std::stoi(startDateYear) > std::stoi(endDateYear)){
        return false;
    }else if(std::stoi(startDateYear) == std::stoi(endDateYear)){

        if(std::stoi(startDateMonthNum) > std::stoi(endDateMonthNum)){
            return false;
        }else if(std::stoi(startDateMonthNum) == std::stoi(endDateMonthNum)){

            if(std::stoi(startDateDay) > std::stoi(endDateDay)) {
                return false;
            }
        }
    }

    if(std::stoi(endDateYear) < currentYear()){
        return false;
    }else if(std::stoi(endDateYear) == currentYear()){

        if(std::stoi(endDateMonthNum) < currentMonthNum() + 1){
            return false;
        }else if(std::stoi(endDateMonthNum) == currentMonthNum() + 1){

            if(std::stoi(endDateDay) < currentDayOfTheMonth()){
                return false;
            }
        }
    }

    return true;
}

bool validFirstDayOfTheWeek(const char* value){

    if(strcmp(value, "Sun") != 0 && strcmp(value, "Mon") != 0){
        return false;
    }
    return true;
}
