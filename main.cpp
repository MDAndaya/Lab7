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
void printSchedule()
{
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
}

int main () {

    vector<Course> courses;

    //TODO read from courses.txt
    ifstream file;
    file.open("../courses.txt");
    string line;
    while (getline(file, line, '\n')) {
        istringstream iss(line);

        string course;
        char dayChar;
        unsigned int timeStart;
        unsigned int timeEnd;

        iss >> course;
        iss >> dayChar;
        Course::dayOfWeek day;
        switch (dayChar) {
            case 'M':
                

        }
        iss >> timeStart;
        iss >> timeEnd;

        Course{course, day, timeStart, timeEnd};
        courses.
    }

    //TODO store data in an STL container
    //TODO sort your STL container with the sort algorithm
    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    //TODO print out schedule
    cout << "Find the TODOs in the code and implement them." << endl;
    cout << "Add/modify any functions/code you need to complete your task." << endl;
    return 0;
}