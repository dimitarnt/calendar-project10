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
* <header file with functions that form the calendar structure>
*
*/

bool sundayIsStartOfWeek(){
    std::string buffer;

    std::fstream reading;

    reading.open(SUN_MON_FILE_NAME, std::fstream::in);

    if(reading.is_open()) {

        getline(reading, buffer);

        if (buffer.empty()) {
            reading.close();
            return true;
        }
        if(buffer == "1"){
            reading.close();
            return true;
        }
        if(buffer == "0"){
            reading.close();
            return false;
        }
    }
}

int firstDayOfTheMonth(const int monthNum, const int year){
    const int startingYear = 1900;
    int leapYears = 0;
    int normalYears = 0;

    for(int i = startingYear; i < year; ++i){

        if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)){
            leapYears++;
        }else{
            normalYears++;
        }
    }

    int totalDaysSince1900 = normalYears * daysInANormalYear + leapYears * daysInALeapYear;

    for(int i = 0; i < monthNum; ++i){

        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
            totalDaysSince1900 += numberOfDaysInAMonthArrayLeap[i];
        }else{
            totalDaysSince1900 += numberOfDaysInAMonthArray[i];
        }
    }

    if(sundayIsStartOfWeek()){
        return (totalDaysSince1900 + 1) % 7;
    }else{
        return totalDaysSince1900 % 7;
    }
}

void calendar(){
    const int spacesInColumns = 5;
    const int spacesBetweenColumns = 5;
    const int spacesInARow = 7 * spacesInColumns + 6 * spacesBetweenColumns;

    int monthNum = 0;
    int year = 0;
    int monthIndent = 0;
    int numberOfDays = 0;
    char inputString[1024] = {};

    std::cout << std::endl;

    std::cout << "Enter month (MM/YYYY):";
    std::cin >> inputString;

    while(!validCalendarAndScheduleInput(inputString)){
        std::cout << "Invalid input" << std::endl;
        std::cout << "Enter month (MM/YYYY):";
        std::cin >> inputString;
    }

    monthNum = getMonthNumPartial(inputString);
    year = getYearPartial(inputString);

    std::cout << std::endl;

    monthIndent = (spacesInARow - lengthOfTextInFirstLine[monthNum]) / 2;
    for(int j = 0;  j < monthIndent; ++j){
        std::cout << " ";
    }
    std::cout << monthArray[monthNum] << " " << year;

    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        numberOfDays = numberOfDaysInAMonthArrayLeap[monthNum];
    }else{
        numberOfDays = numberOfDaysInAMonthArray[monthNum];
    }

    std::cout << std::endl;

    for(int i = 0; i < daysInAWeek; ++i){
        if(currentMonthNum() == monthNum && currentYear() == year &&
           (currentDayOfTheMonth() + firstDayOfTheMonth(monthNum, year) - 1) % 7 == i){

            for(int j = 0; j < spacesInColumns / 2 - 2 + spacesInColumns % 2; ++j){
                std::cout << " ";
            }

            if(sundayIsStartOfWeek()){
                std::cout << "[" << dayOfTheWeekShortenedSundayStart[i] << "]";
            }else{
                std::cout << "[" << dayOfTheWeekShortenedMondayStart[i] << "]";
            }

            for(int j = 0; j < spacesInColumns / 2 - 2; ++j){
                std::cout << " ";
            }
        }else{

            for(int j = 0; j < spacesInColumns / 2 - 1 + spacesInColumns % 2; ++j){
                std::cout << " ";
            }

            if(sundayIsStartOfWeek()){
                std::cout << dayOfTheWeekShortenedSundayStart[i];
            }else{
                std::cout << dayOfTheWeekShortenedMondayStart[i];
            }

            for(int j = 0; j < spacesInColumns / 2 - 1; ++j){
                std::cout << " ";
            }
        }

        for(int j = 0; j < spacesBetweenColumns; ++j){
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    for(int i = 0; i < firstDayOfTheMonth(monthNum, year); ++i){

        for(int j = 0; j < (spacesInColumns + spacesBetweenColumns); ++j){
            std::cout << " ";
        }
    }

    for(int i = 0; i < numberOfDays; ++i){
        if((i + firstDayOfTheMonth(monthNum , year)) % 7 == 0 && i != 0){
            std::cout << std::endl;
        }

        if((i + 1) / 10 == 0){

            if((i + 1) == currentDayOfTheMonth() && currentMonthNum() == monthNum && currentYear() == year){
                for(int j = 0; j < spacesInColumns / 2 - 1; ++j){
                    std::cout << " ";
                }
                std::cout << "[" << i + 1 << "]";
                for(int j = 0; j < spacesInColumns / 2 - 2 + spacesInColumns % 2; ++j){
                    std::cout << " ";
                }
            }else{
                for(int j = 0; j < spacesInColumns / 2; ++j){
                    std::cout << " ";
                }
                std::cout << i + 1;
                for(int j = 0; j < spacesInColumns / 2 - 1 + spacesInColumns % 2; ++j){
                    std::cout << " ";
                }
            }
        }else{

            if((i + 1) == currentDayOfTheMonth() && currentMonthNum() == monthNum && currentYear() == year){
                for(int j = 0; j < spacesInColumns / 2 - 2 + spacesInColumns % 2; ++j){
                    std::cout << " ";
                }
                std::cout << "[" << i + 1 << "]";
                for(int j = 0; j < spacesInColumns / 2 - 2; ++j){
                    std::cout << " ";
                }
            }else{
                for(int j = 0; j < spacesInColumns / 2 - 1 + spacesInColumns % 2; ++j){
                    std::cout << " ";
                }
                std::cout << i + 1;
                for(int j = 0; j < spacesInColumns / 2 - 1; ++j){
                    std::cout << " ";
                }
            }

        }

        if(getNumberOfEventsPerDay((i + 1), monthNum, year) > 0){
            std::cout << "(" << getNumberOfEventsPerDay((i + 1), monthNum, year) << ")";

            for(int j = 0; j < spacesBetweenColumns - 3; ++j){
                std::cout << " ";
            }
        }else{

            for(int j = 0; j < spacesBetweenColumns; ++j){
                std::cout << " ";
            }
        }
    }

    std::cout << std::endl;
}

void changeTheFirstDayOfTheWeek(){
    char value[2] = {};
    std::string buffer;

    std::cout << std::endl;

    if(sundayIsStartOfWeek()){
        std::cout << "The first day of the week is currently Sunday." << std::endl << std::endl;
    }else{
        std::cout << "The first day of the week is currently Monday." << std::endl << std::endl;
    }

    std::fstream writing;

    writing.open(SUN_MON_FILE_NAME, std::fstream::out);

    if(writing.is_open()){

        std::cout << "Enter new (Mon / Sun):";
        std::cin >> value;

        while(!validFirstDayOfTheWeek(value)){
            std::cout << "Invalid input" << std::endl;
            std::cout << "Enter new (Mon / Sun):";
            std::cin >> value;
        }

        if(strcmp(value, "Sun") == 0){
            writing << "1";
        }
        if(strcmp(value, "Mon") == 0){
            writing << "0";
        }
    }
    writing.close();

    std::cout << std::endl << "Saved!" << std::endl;
}
