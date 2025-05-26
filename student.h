#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Student{
    private:
        int id;
        string name;
        double gpa;
    public:
        Student();
        Student(int, const string&, double);

        int getId() const;
        string getName() const;
        double getGpa() const;
        void setName(const string& newName);
        void setGpa(double newGpa);
        void display() const;

        string toFileString() const;
        void fromFileString(const string& line);

        bool operator==(const Student& rhs) const;
        friend ostream& operator<<(ostream& os, const Student& s);
};

#endif