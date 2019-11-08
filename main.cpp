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

void printSchedule()
{
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
}

void checkConflicts() {
    for (auto i = courses.begin(), j = i + 1; j != courses.end(); i++, j++) {
        if (i->getDay() == j->getDay() &&
            i->getStartTime() <= j->getFinishTime() && j->getStartTime() <= i->getFinishTime()) {
            cout << "CONFLICT:\n" << *i << "\n" << *j << '\n' << endl;

        }
    }
}


int main () {

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
            default:
                ;
        }
        iss >> startTime;
        iss >> finishTime;

        Course c{title, day, startTime, finishTime};
        courses.push_back(c);
    }

    // Sort STL
    sort(courses.begin(), courses.end());

    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    checkConflicts();
    //TODO print out schedule


    return 0;
}