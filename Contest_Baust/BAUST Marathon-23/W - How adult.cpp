#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class diff{
public:
    int year, month, day;

    diff(){
        year = 0;
        month = 0;
        day = 0;
    }

    string operator-(diff a){
        int year_diff = year - a.year;
        int month_diff = month - a.month;
        int day_diff = day - a.day;

        if (day_diff < 0){
            day_diff += 30;
            month_diff--;
        }
        if (month_diff < 0){
            month_diff += 12;
            year_diff--;
        }
        //cout<<day_diff<<" "<<month_diff<<" "<<year_diff<<endl;
        return (year_diff < 0) ? "Invalid birth date" : (year_diff > 130) ? "Check birth date" : to_string(year_diff);
    }
};

int main(){
    diff a, b;
    int test;
    cin >> test;
    string date1, date2;
    char div;
    for (int i = 1; i <= test; i++){
        cin >> date1 >> date2;
        stringstream ss1(date1), ss2(date2);
        ss1 >> a.day >> div >> a.month >> div >> a.year;
        ss2 >> b.day >> div >> b.month >> div >> b.year;

        cout << "Case #" << i << ": " << a - b << endl;
    }
    return 0;
}