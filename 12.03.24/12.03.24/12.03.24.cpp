#include <iostream>
#include <ctime>
#include <string>
#include <set>
#include "stu.h"
using namespace std;


class Aspirant : public Student {
private:
    string candidate_work;
public:
    Aspirant() {
        SetCandidateWork("C++");
    }
    Aspirant(string surname, string name, string middlname, string adress, string phonenumber, string candidate_work)
        : Student(surname, name, middlname, adress, phonenumber) {
        SetCandidateWork(candidate_work);
    }
    void SetCandidateWork(string candidate_work) {
        this->candidate_work = candidate_work;
    }
    string GetCandidateWork() const {
        return candidate_work;
    }
    void PrintStudent() const {
        cout << "Surname: " << surname << "\n";
        cout << "Name: " << name << "\n";
        cout << "Middlename: " << middlename << "\n";
        cout << "Adress: " << adress << "\n";
        cout << "Phonenumber: " << phonenumber << "\n";
        cout << "Candidate work: " << candidate_work << "\n";
    }
};

class Date {
    unsigned short day;
    unsigned short month;
    long long year;
public:
    Date() : Date(23, 12, 2023) {}

    Date(unsigned short day, unsigned short month, long long year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }
    Date(unsigned short day, unsigned short month) : Date(day, month, 2005) {}


    void PrintDate() const
    {
        cout << day << "." << month << "." << year << "\n";
    }
    void SetDay(unsigned short day)
    {
        if (day == 0 || day > 31) throw "ERROR!!! The day must be from 0 to 31 !!!";
        this->day = day;
    }
    unsigned short GetDay() const
    {
        return day;
    }
    void SetMonth(unsigned short month)
    {
        if (month == 0 || month > 12) throw "ERROR!!! The day must be from 1 to 12 !!!";
        this->month = month;
    }

    unsigned short GetMonth() const
    {
        return month;
    }
    void SetYear(long long year)
    {
        this->year = year;
    }
    long long GetYear() const
    {
        return year;
    }

    bool IsLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int DaysInMonth(int month, int year) {
        switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return IsLeapYear(year) ? 29 : 28;
        default:
            return -1;
        }
    }

    operator string()
    {
        return to_string(day) + "." + to_string(month) + "." + to_string(year);
    }

    Date& operator ++ ()
    {
        day++;
        if (day > DaysInMonth(month, year))
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date& operator -- ()
    {
        day--;
        if (day < 1)
        {
            month--;
            day = DaysInMonth(month, year);
            if (month < 1)
            {
                year--;
                month = 12;
                day = DaysInMonth(month, year);
            }
        }
        return *this;
    }

    Date& operator ++ (int x)
    {
        Date copy = *this;
        this->day++;
        if (this->day > DaysInMonth(this->month, this->year))
        {
            this->day = 1;
            this->month++;
            if (month > 12)
            {
                this->month = 1;
                this->year++;
            }
        }
        return copy;
    }


    Date& operator -- (int x)
    {
        Date copy = *this;
        this->day--;
        if (day < 1)
        {
            this->month--;
            this->day = DaysInMonth(this->month, this->year);
            if (month < 1)
            {
                this->year--;
                this->month = 12;
                day = DaysInMonth(month, year);
            }
        }
        return copy;
    }
};

int main()
{
    Aspirant as;
    as.PrintStudent();
}