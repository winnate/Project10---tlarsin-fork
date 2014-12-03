#include <iostream>
using namespace std;
/*
        Tristan Larsin
        CS-1511
        12-1-2014
        This program finds the day for
        the date that the user enters
        using a class called DayOfYear.

*/

class DayOfYear {
        public:
                void input();
                void process();
                bool isLeapYear(int year);
                int getCenturyValue(int year);
                int getYearValue(int year);
                int getMonthValue(int month, int year);
                void getDay(int actualDay);
        private:
                int month, day, year, actualDay;

};

int main() {
        // Declaration
        DayOfYear date;
        char answer;
        //Function Call;
        do{
                date.process();
                do{
                cout << "Would you like to try again? (Y/N): ";
                cin >> answer;  }
        while(!(answer == 'Y') && !(answer == 'y') && !(answer == 'N') && !(answer == 'n'));

        }
        while((answer == 'Y') || (answer == 'y'));

        cout << endl << "Goodbye." << endl;
}

void DayOfYear::input() {
        cout << "Only numerical values please." << endl;
        do {
                cout << "Please enter in the day, month and year: ";
                cin >> day;
                cin >> month;
                cin >> year;
        }
        while((day < 1) || (day > 31) || (month < 1) || (month > 12) || (year < 1) );

}

void DayOfYear::process(){
        input();
        isLeapYear(year);
        getCenturyValue(year);
        getYearValue(year);
        getMonthValue(month, year);
        actualDay = day + getCenturyValue(year) + getYearValue(year) + getMonthValue(month, year);
        getDay(actualDay);
}

bool DayOfYear::isLeapYear(int year) {
        if(year % 400 == 0)
                return true;
        else
                return false;
}

int DayOfYear::getCenturyValue(int year) {
        int first2, rem;
        first2 = year / 100;
        rem = first2 % 4;
        return (3 - rem) *2;
}

int DayOfYear::getYearValue(int year) {
        int last2, result;
        last2 = year % 100;
        result = last2 / 4;
        return last2 + result;
}

int DayOfYear::getMonthValue(int month, int year) {
        switch(month) {
        case 1:
                if(!(year % 400) == 0)
                        return 6;
                else
                        return 0;
        case 2:
                if(!(year % 400) == 0)
                        return 2;
                else
                        return 3;
        case 3:
                return 3;
        case 4:
                return 6;
        case 5:
                return 1;
        case 6:
                return 4;
        case 7:
                return 6;
        case 8:
                return 2;
        case 9:
                return 5;
        case 10:
                return 0;
        case 11:
                return 3;
        case 12:
                return 5; }
}

void DayOfYear::getDay(int actualDay) {
        int remainder;
        remainder = actualDay % 7;
                switch(remainder) {
        case 0:
                cout << endl << "The day is a Sunday." << endl;
                break;
        case 1:
                cout << endl << "The day is a Monday." << endl;
                break;
        case 2:
                cout << endl << "The day is a Tuesday." << endl;
                break;
        case 3:
                cout << endl << "The day is a Wednesday." << endl;
                break;
        case 4:
                cout << endl << "The day is a Thursday." << endl;
                break;
        case 5:
                cout << endl << "The day is a Friday." << endl;
                break;
        case 6:
                cout << endl << "The day is a Saturday." << endl;
                break;
        }

}
