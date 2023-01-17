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
* <file with source code>
*
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <vector>

#include "constants.h"
#include "math_functions.h"
#include "get_functions.h"
#include "current_day_assessment_functions.h"
#include "validating_input_functions.h"
#include "../project10/calendar_structure_functions.h"
#include "event_functions.h"

int main() {
    char option[2] = {};

    std::cout << "Welcome! Today is ";
    currentDayOfTheWeek();

    std::cout << ", ";
    std::cout << currentDayOfTheMonth();

    std::cout << " ";
    currentMonth();

    std::cout << " ";
    std:: cout << currentYear();
    std::cout << ".";

    eventsTodayOrTomorrow();

    std::cout << "Choose an option:\n";
    std::cout << "\t1. Show calendar\n";
    std::cout << "\t2. Show schedule\n";
    std::cout << "\t3. List events\n";
    std::cout << "\t4. Add event\n";
    std::cout << "\t5. Remove event\n";
    std::cout << "\t6. Set first weekday";

    std::cout << std::endl << std::endl;

    std::cout << "Enter your choice:";
    std::cin >> option;

    while(!validOptionInput(option)){
        std::cout << "Invalid input" << std::endl;
        std::cout << "Enter your choice:";
        std::cin >> option;
    }

    switch(std::stoi(option)){
        case(1):
            calendar();
            break;

        case(2):
            schedule();
            break;

        case(3):
            listEvents();
            break;

        case(4):
            addEvent();
            break;

        case(5):
            deleteEvent();
            break;

        case(6):
            changeTheFirstDayOfTheWeek();
            break;
    }

    return 0;
}
