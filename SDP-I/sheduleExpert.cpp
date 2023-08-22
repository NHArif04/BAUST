#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DateTime {
public:
    int year;
    int month;
    int day;
    int hour;
    int minute;

    DateTime(int y, int m, int d, int h, int min) {
        year = y;
        month = m;
        day = d;
        hour = h;
        minute = min;
    }

    bool operator<(const DateTime& other) const {
        if (year < other.year)
            return true;
        else if (year > other.year)
            return false;

        if (month < other.month)
            return true;
        else if (month > other.month)
            return false;

        if (day < other.day)
            return true;
        else if (day > other.day)
            return false;

        if (hour < other.hour)
            return true;
        else if (hour > other.hour)
            return false;

        return minute < other.minute;
    }

    bool operator>(const DateTime& other) const {
        return other < *this;
    }

    DateTime operator+(int minutes) const {
        DateTime result(*this);
        result.minute += minutes;
        result.hour += result.minute / 60;
        result.minute %= 60;
        result.day += result.hour / 24;
        result.hour %= 24;
        return result;
    }

    DateTime operator-(int minutes) const {
        DateTime result(*this);
        result.minute -= minutes;
        if (result.minute < 0) {
            result.hour -= 1;
            result.minute += 60;
        }
        if (result.hour < 0) {
            result.day -= 1;
            result.hour += 24;
        }
        return result;
    }
};

class Event {
public:
    string name;
    DateTime start;
    DateTime end;

    Event(string n, DateTime s, DateTime e) {
        name = n;
        start = s;
        end = e;
    }
};

class RepeatingEvent : public Event {
public:
    string frequency;

    RepeatingEvent(string n, DateTime s, DateTime e, string f) :
        Event(n, s, e) {
        frequency = f;
    }
};

class Calendar {
private:
    vector<Event> events;

public:
    void addEvent(Event e) {
        events.push_back(e);
        sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
            return a.start < b.start;
        });
    }

    void viewDay(DateTime date) {
        cout << "Events on " << date.day << "/" << date.month << endl;

        for (Event e : events) {
            if (e.start.day == date.day && e.start.month == date.month) {
                cout << e.name << endl;
            }
        }
    }

    DateTime suggestTime(int duration) {
        DateTime start(2023, 2, 1, 9, 0);
        DateTime end(2023, 2, 1, 17, 0);

        bool available;

        do {
            available = true;

            for (Event e : events) {
                if (e.start < end && e.end > start) {
                    available = false;
                    start = e.end;
                }
            }

            end = start + duration;

        } while (!available);

        return start;
    }
};

int main() {
    Calendar calendar;

    Event e1("Meeting", DateTime(2023, 2, 1, 10, 0), DateTime(2023, 2, 1, 11, 0));
    calendar.addEvent(e1);

    RepeatingEvent e2("Fitness Class", DateTime(2023, 2, 1, 5, 0), DateTime(2023, 2, 1, 6, 0), "Daily");
    calendar.addEvent(e2);

    DateTime date(2023, 2, 1);
    calendar.viewDay(date);

    DateTime suggest = calendar.suggestTime(30);
    cout << "Suggested time: " << suggest.hour << ":" << suggest.minute << endl;

    return 0;
}