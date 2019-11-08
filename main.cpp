#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */

vector<Course> courses;

void printSchedule() {
    ostream_iterator<Course> osi(cout, "\n");
    copy(courses.begin(), courses.end(), osi);
}

void checkConflicts() {
    for (auto iteri = courses.begin(); iteri != courses.end(); iteri++) {
        for (auto iterj = iteri + 1; iterj != courses.end(); iterj++) {
            if (iteri->getDay() == iterj->getDay() &&
                iterj->getStartTime() <= iteri->getFinishTime()) {
                cout << "CONFLICT:\n" << *iteri << "\n" << *iterj << '\n' <<  endl;
            }
        }
    }
}

int main() {

    // Read from file and put into STL
    ifstream file;
    file.open("../courses.txt");
    string line;
    while (getline(file, line, '\n')) {
        istringstream iss(line);

        string title;
        char dayChar;
        unsigned int startTime;
        unsigned int finishTime;

        iss >> title;
        iss >> dayChar;
        Course::dayOfWeek day;
        switch (dayChar) {
            case 'M':
                day = Course::MON;
                break;
            case 'T':
                day = Course::TUE;
                break;
            case 'W':
                day = Course::WED;
                break;
            case 'R':
                day = Course::THUR;
            case 'F':
                day = Course::FRI;
                break;
            default:;
        }
        iss >> startTime;
        iss >> finishTime;

        Course c{title, day, startTime, finishTime};
        courses.push_back(c);
    }

    // Sort STL
    sort(courses.begin(), courses.end());
    // Check conflicts
    checkConflicts();
    // Print schedule
    printSchedule();

    return 0;
}