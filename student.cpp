#include "student.h"

Student::Student(){
    id = 0;
    name = "";
    gpa = 0.0;
}

Student::Student(int newId, const string& newName, double newGpa){
    id = newId;
    name = newName;
    gpa = newGpa;
}

int Student::getId() const{
    return id;
}

string Student::getName() const{
    return name;
}
double Student::getGpa() const{
    return gpa;
}

void Student::setName(const string& newName){
    name = newName;
}

void Student::setGpa(double newGpa){
    gpa = newGpa;
}

void Student::display() const{
    cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
}

bool Student::operator==(const Student& rhs) const{
    return this->id == rhs.id;
}

ostream& operator<<(ostream& os, const Student& s){
    os << "ID: " << s.id << " | Name: " << s.name << " | GPA: " << s.gpa << endl;
    return os;
}

string Student::toFileString() const{
    ostringstream oss;
    oss << id << "|" << name << "|" << gpa;
    return oss.str();
}

void Student::fromFileString(const string& line){
    istringstream iss(line);
    string token;

    getline(iss, token, '|');
    id = stoi(token);
    getline(iss, name, '|');
    getline(iss, token, '|');
    gpa = stod(token);
}