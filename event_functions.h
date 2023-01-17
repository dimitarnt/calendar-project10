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
* <header file with functions regarding events>
*
*/

void sortEventsWithNewEvent(const char* name, const char* startDate, const char* endDate){
    const int yearSpacingInVector = 4;
    const int monthNumSpacingInVector = 2;

    int startDay = getDayFull(startDate);
    int startMonthNum = getMonthNumFull(startDate);
    int startYear = getYearFull(startDate);

    int endDay = getDayFull(endDate);
    int endMonthNum = getMonthNumFull(endDate);
    int endYear = getYearFull(endDate);

    std::vector<std::vector<std::string>> events = {};
    std::vector<std::string> temp;

    std::string buffer;
    std::string nameString;
    std::string date;
    char* dateChar = {};

    std::ifstream reading;
    std::ofstream appending;

    temp.emplace_back(name);
    temp.push_back(std::to_string(startYear * pow(10, yearSpacingInVector) + (startMonthNum + 1) * pow(10, monthNumSpacingInVector) + startDay));
    events.push_back(temp);
    temp.clear();

    if(strcmp(startDate, endDate) != 0){

        for(int i = 1; startDay != endDay || startMonthNum != endMonthNum || startYear != endYear; ++i){

            if(startYear % 400 == 0 || (startYear % 4 == 0 && startYear % 100 != 0)){

                if(startDay == numberOfDaysInAMonthArrayLeap[numberOfMonths - 1] && startMonthNum == numberOfMonths - 1){

                    startDay = 1;
                    startMonthNum = 0;
                    startYear++;
                }else if(startDay == numberOfDaysInAMonthArrayLeap[startMonthNum]){

                    startDay = 1;
                    startMonthNum += 1;
                }else{

                    startDay += 1;
                }

            }else{

                if(startDay == numberOfDaysInAMonthArray[numberOfMonths - 1] && startMonthNum == numberOfMonths - 1){

                    startDay = 1;
                    startMonthNum = 0;
                    startYear++;
                }else if(startDay == numberOfDaysInAMonthArray[startMonthNum]){

                    startDay = 1;
                    startMonthNum += 1;
                }else{

                    startDay += 1;
                }
            }

            temp.emplace_back(name);
            temp.push_back(std::to_string(startYear * pow(10, yearSpacingInVector) + (startMonthNum + 1) * pow(10, monthNumSpacingInVector) + startDay));
            events.push_back(temp);
            temp.clear();

        }
    }

    reading.open("events.txt");

    if(reading.is_open()){

        while(getline(reading, buffer)){
            int positionOfDelimiter = buffer.find(':');
            nameString = buffer.substr(0, positionOfDelimiter);
            date = buffer.substr(positionOfDelimiter + 1);
            dateChar = &date[0];

            startDay = getDayFull(dateChar);
            startMonthNum = getMonthNumFull(dateChar);
            startYear = getYearFull(dateChar);

            temp.emplace_back(nameString);
            temp.push_back(std::to_string(startYear * pow(10, yearSpacingInVector) + (startMonthNum + 1) * pow(10, monthNumSpacingInVector) + startDay));
            events.push_back(temp);
            temp.clear();
        }
    }

    reading.close();

    for(int i = 0; i < events.size(); ++i){
        for(int j = i + 1; j < events.size(); ++j){

            if(events[j][1] < events[i][1]){
                std::string tempName = events[j][0];
                events[j][0] = events[i][0];
                events[i][0] = tempName;

                std::string tempDate = events[j][1];
                events[j][1] = events[i][1];
                events[i][1] = tempDate;
            }

            if(events[j][1] == events[i][1]){

                if(events[j][0] < events[i][0]){
                    std::string tempName = events[j][0];
                    events[j][0] = events[i][0];
                    events[i][0] = tempName;

                    std::string tempDate = events[j][1];
                    events[j][1] = events[i][1];
                    events[i][1] = tempDate;
                }
            }
        }
    }

    appending.open(TEMP_FILE_NAME, std::ios::app);

    if(appending.is_open()){

        for(int i = 0; i < events.size(); ++i){

            appending << events[i][0] << ":";

            appending << events[i][1][6] << events[i][1][7] << "/";

            appending << events[i][1][4] << events[i][1][5] << '/';

            appending << events[i][1][0] << events[i][1][1] << events[i][1][2] << events[i][1][3];

            appending << "\n";
        }
    }

    appending.close();

    remove(EVENTS_FILE_NAME);
    rename(TEMP_FILE_NAME, EVENTS_FILE_NAME);
}

void eventsTodayOrTomorrow(){

    int day = 0;
    int monthNum = 0;
    int year = 0;
    int countToday = 0;
    int countTomorrow = 0;

    std::string buffer;
    std::string date;
    char* dateChar;

    std::fstream reading;

    reading.open(EVENTS_FILE_NAME);

    if(reading.is_open()){

        while(getline(reading, buffer)) {

            int positionOfDelimiter = buffer.find(':');
            date = buffer.substr(positionOfDelimiter + 1);
            dateChar = &date[0];

            day = getDayFull(dateChar);
            monthNum = getMonthNumFull(dateChar);
            year = getYearFull(dateChar);

            if(day == currentDayOfTheMonth() && monthNum == currentMonthNum() && year == currentYear()) {
                countToday++;
            }

            if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {

                if(currentDayOfTheMonth() == numberOfDaysInAMonthArrayLeap[numberOfMonths - 1] && currentMonthNum() == numberOfMonths - 1) {

                    if(day == 1 && monthNum == 0 && year == currentYear() + 1) {
                        countTomorrow++;
                    }
                }else if(currentDayOfTheMonth() == numberOfDaysInAMonthArrayLeap[currentMonthNum()]) {

                    if(day == 1 && monthNum == currentMonthNum() + 1 && year == currentYear()) {
                        countTomorrow++;
                    }
                }else{

                    if(day == currentDayOfTheMonth() + 1 && monthNum == currentMonthNum() && year == currentYear()) {
                        countTomorrow++;
                    }
                }

            }else{

                if(currentDayOfTheMonth() == numberOfDaysInAMonthArray[numberOfMonths - 1] && currentMonthNum() == numberOfMonths - 1) {

                    if(day == 1 && monthNum == 1 && year == currentYear() + 1) {
                        countTomorrow++;
                    }
                }else if(currentDayOfTheMonth() == numberOfDaysInAMonthArray[currentMonthNum()]) {

                    if(day == 1 && monthNum == currentMonthNum() + 1 && year == currentYear()) {
                        countTomorrow++;
                    }
                }else{

                    if(day == currentDayOfTheMonth() + 1 && monthNum == currentMonthNum() && year == currentYear()) {
                        countTomorrow++;
                    }
                }
            }

        }

    }
    reading.close();

    if(countToday != 0 || countTomorrow != 0){
        std::cout << std::endl;
    }

    if(countToday != 0){

        std::cout << std::endl;
        std::cout << "You have " << countToday;

        if(countToday == 1){
            std::cout << " event today.";
        }
        if(countToday > 1){
            std::cout << " events today.";
        }
    }

    if(countTomorrow != 0){

        std::cout << std::endl;
        std::cout << "You have " << countTomorrow;

        if(countTomorrow == 1){
            std::cout << " event tomorrow.";
        }
        if(countTomorrow > 1){
            std::cout << " events tomorrow.";
        }
    }

    std::cout << std::endl << std::endl;
}

void schedule(){

    bool areThereAnyEvents = false;
    int dayOfTheWeekEvent = 0;
    int monthNum = 0;
    int year = 0;
    int count = 0;
    char inputString[1024] = {};

    std::string buffer;
    std::string name;
    std::string date;
    char* nameChar;
    char* dateChar;

    std::vector<std::string> eventNamesThatWereMet;

    std::fstream reading;

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

    std::cout << monthArray[monthNum] << " " << year << std::endl;

    for(int i = 0; i < lengthOfTextInFirstLine[monthNum]; ++i){
        std::cout << "-";
    }

    std::cout << std::endl;

    reading.open(EVENTS_FILE_NAME);

    if(reading.is_open()){

        while(getline(reading, buffer)){

            int positionOfDelimiter = buffer.find(':');
            name = buffer.substr(0, positionOfDelimiter);
            date = buffer.substr(positionOfDelimiter + 1);
            nameChar = &name[0];
            dateChar = &date[0];

            eventNamesThatWereMet.push_back(name);

            if(monthNum == getMonthNumFull(dateChar) && year == getYearFull(dateChar)){
                areThereAnyEvents = true;

                if(sundayIsStartOfWeek()){
                    dayOfTheWeekEvent = (firstDayOfTheMonth(monthNum, year) + getDayFull(dateChar) - 1) % 7;
                    std::cout << dayOfTheWeekShortenedSundayStart[dayOfTheWeekEvent] << ", ";
                }else{
                    dayOfTheWeekEvent = (firstDayOfTheMonth(monthNum, year) + getDayFull(dateChar) - 1) % 7;
                    std::cout << dayOfTheWeekShortenedMondayStart[dayOfTheWeekEvent] << ", ";
                }

                std::cout << getDayFull(dateChar) << "\t ";

                if(getNumberOfDaysPerEvent(nameChar) > 1){

                    count = 0;

                    for(int i = 0; i < eventNamesThatWereMet.size(); ++i){
                        if(eventNamesThatWereMet[i] == name){
                            count++;
                        }
                    }

                    std::cout << name << " ";
                    std::cout << "(Day " << count << "/" << getNumberOfDaysPerEvent(nameChar) << ")";
                    std::cout << std::endl;
                    continue;
                }

                std::cout << name;
                std::cout << std::endl;
            }

        }

    }
    reading.close();

    if(!areThereAnyEvents){
        std::cout << "There are no events this month." << std::endl;
    }

}

void listEvents(){
    std::string buffer;
    std::string name;
    std::string date;
    char* nameChar;
    char* dateChar;

    int day = 0;
    int monthNum = 0;
    int year = 0;

    std::vector<std::string> eventsToIgnore;

    std::cout << std::endl;
    std::cout << "You have the following events:" << std::endl;

    std::ifstream data(EVENTS_FILE_NAME);

    if(data.is_open()){

        int i = 0;
        while(getline(data, buffer)){
            bool eventShouldBeSkipped = false;

            int positionOfDelimiter = buffer.find(':');
            name = buffer.substr(0, positionOfDelimiter);
            date = buffer.substr(positionOfDelimiter + 1);
            nameChar = &name[0];
            dateChar = &date[0];

            for(int j = 0; j < eventsToIgnore.size(); ++j){
                if(eventsToIgnore[j] == name){
                    eventShouldBeSkipped = true;
                }
            }

            if(eventShouldBeSkipped){
                continue;
            }

            eventsToIgnore.push_back(name);

            i++;

            std::cout << i << ". " << name << " ";

            if(getNumberOfDaysPerEvent(nameChar) > 1){

                std::cout << "(" << date << " - ";

                day = getDayFull(dateChar);
                monthNum = getMonthNumFull(dateChar);
                year = getYearFull(dateChar);

                for(int j = 1; j < getNumberOfDaysPerEvent(nameChar); ++j){
                    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){

                        if(day == numberOfDaysInAMonthArrayLeap[numberOfMonths - 1] && monthNum == numberOfMonths - 1){

                            day = 1;
                            monthNum = 0;
                            year++;
                        }else if(day == numberOfDaysInAMonthArrayLeap[monthNum]){

                            day = 1;
                            monthNum += 1;
                        }else{

                            day += 1;
                        }

                    }else{

                        if(day == numberOfDaysInAMonthArray[numberOfMonths - 1] && monthNum == numberOfMonths - 1){

                            day = 1;
                            monthNum = 0;
                            year++;
                        }else if(day == numberOfDaysInAMonthArray[monthNum]){

                            day = 1;
                            monthNum += 1;
                        }else{

                            day += 1;
                        }
                    }
                }

                if(day / 10 == 0 && (monthNum + 1) / 10 == 0){
                    std::cout << "0" << day << '/' << "0" << monthNum + 1 << '/' << year << ")";
                }else if(day / 10 == 0){
                    std::cout << "0" << day << '/' << monthNum + 1 << '/' << year << ")";
                }else if((monthNum + 1) / 10 == 0){
                    std::cout << day << '/' << "0" << monthNum + 1 << '/' << year << ")";
                }else{
                    std::cout << day << '/' << monthNum + 1 << '/' << year << ")";
                }

            }else{
                std::cout << "(" << date << ")";
            }

            std::cout << std::endl;
        }
    }
    data.close();
}

void addEvent(){
    char name[1024] = {};
    char startDate[11] = {};
    char endDate[11] = {};

    std::cout << std::endl;

    std::cin.ignore();

    std::cout << "Enter name:";
    std::cin.getline(name, 1024);

    while(!validEventNameInput(name)){
        std::cout << "Invalid input" << std::endl;
        std::cout << "Enter name:";
        std::cin.getline(name, 1024);
    }

    std::cout << "Enter start date (DD/MM/YYYY):";
    std::cin.getline(startDate, 11);

    while(!validEventDateInput(startDate)){
        std::cout << "Invalid input" << std::endl;
        std::cout << "Enter start date (DD/MM/YYYY):";
        std::cin.getline(startDate, 11);
    }

    std::cout << "Enter end date (DD/MM/YYYY):";
    std::cin.getline(endDate, 11);

    while(!validEventDateInput(endDate) || !validEventEndDateInput(startDate, endDate)){
        std::cout << "Invalid input" << std::endl;
        std::cout << "Enter end date (DD/MM/YYYY):";
        std::cin.getline(endDate, 11);
    }

    sortEventsWithNewEvent(name, startDate, endDate);

    std::cout << std::endl << "Event added successfully!" << std::endl;
}

void deleteEvent(){
    std::string buffer;
    std::string temp;
    std::string name;

    std::cout << std::endl;

    std::cout << "Enter name:";
    std::getline(std::cin.ignore(), name);

    std::ifstream reading;
    std::ofstream appending;

    reading.open(EVENTS_FILE_NAME);
    appending.open(TEMP_FILE_NAME);

    if(reading.is_open()){

        while(getline(reading, buffer)){
            int positionOfDelimiter = buffer.find(':');
            temp = buffer.substr(0, positionOfDelimiter);
            if(temp != name){
                appending << buffer << std::endl;
            }
        }
    }

    reading.close();
    appending.close();

    remove(EVENTS_FILE_NAME);
    rename(TEMP_FILE_NAME, EVENTS_FILE_NAME);

    std::cout << std::endl << "Event deleted successfully!" << std::endl;
}
