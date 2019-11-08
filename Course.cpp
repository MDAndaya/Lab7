#include "Course.hpp"

using namespace std;

Course::Course(string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time)
        : title(title), day(day), start_time(start_time), finish_time(finish_time) {}

Course::Course(const Course &m) : title(m.title), day(m.day), start_time(m.start_time), finish_time(m.finish_time) {}

Course &Course::operator=(Course m) {
    if (this != &m) {
        title = m.title;
        day = m.day;
        start_time = m.start_time;
        finish_time = m.finish_time;
    }
    return *this;
}

bool Course::operator==(const Course &m) const {
    return (
            title == m.title &&
            day == m.day &&
            start_time == m.start_time &&
            finish_time == m.finish_time
    );
}

bool Course::operator<(const Course &m) const {
    if (day < m.day)
        return true;
    else if (day == m.day && start_time < m.start_time)
        return true;
    else if (day == m.day && start_time == m.start_time && finish_time < m.finish_time)
        return true;
    return false;
}

ostream &operator<<(ostream &os, const Course &m) {
    os << m.getTitle() << " " << m.getDay() << " " << m.getStartTime() << " " << m.getFinishTime();
    return os;
}

const string &Course::getTitle() const {
    return title;
}

Course::dayOfWeek Course::getDay() const {
    return day;
}

unsigned int Course::getStartTime() const {
    return start_time;
}

unsigned int Course::getFinishTime() const {
    return finish_time;
}


