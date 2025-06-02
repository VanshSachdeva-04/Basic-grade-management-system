#include "linkedlist.h"
#include "student.h"
#include <fstream>

void saveToFile(const LinkedList<Student>& studentList, const string& filename);
void loadFromFile(LinkedList<Student>& studentList, const string& filename);

int main(){
    LinkedList<Student> studentList;
    const string dataFile = "students.txt";
    int choice;

    loadFromFile(studentList, dataFile);

    do{
        cout << "######### Student Record Management #########" << endl;
        cout << "1. Display all students" << endl;
        cout << "2. Add student" << endl;
        cout << "3. Get student by postion" << endl;
        cout << "4. Replace student" << endl;
        cout << "5. Remove student" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: " << endl;
        cin >> choice;

        switch(choice){
            case 1: {
                cout << "######### All Students #########" << endl;
                for(int i = 1; i <= studentList.getLength(); i++){
                    cout << i << ". " << studentList.getEntry(i) << endl;
                }
                break;
            }
            case 2: {
                int id;
                string name;
                double gpa;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter GPA: ";
                cin >> gpa;

                Student s(id, name, gpa);
                if(studentList.insert(studentList.getLength() + 1, s)){
                    cout << "Student has been added" << endl;
                }else{
                    cout << "Failed to add the student" << endl;
                }
                break;
            }
            case 3: {
                int pos;
                cout << "Enter postion: ";
                cin >> pos;
                cout << endl;
                if(pos >= 1 && pos <= studentList.getLength()){
                    Student s = studentList.getEntry(pos);
                    cout << s << endl;
                }else{
                    cout << "Error: Invalid postion." << endl;
                }
                break;
            }
            case 4: {
                int pos;
                cout << "Enter position to replace: ";
                cin >> pos;

                int id;
                string name;
                double gpa;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter GPA: ";
                cin >> gpa;

                Student newStudent(id, name, gpa);
                if(pos >= 1 && pos <= studentList.getLength()){
                    Student old = studentList.replace(pos, newStudent);
                    cout << "Replaced Student : " << old << endl;
                }else{
                    cout << "Error, can't replace the student" << endl;
                }
                break;
            }
            case 5: {
                int pos;
                cout << "Enter postion to remove: ";
                cin >> pos;
                if(studentList.remove(pos)){
                    cout << "Student removed." << endl;
                }else{
                    cout << "invalid postion." << endl;
                }
                break;
            }
            case 6: {
                saveToFile(studentList, dataFile);
                cout << "Exiting Program..." << endl;
                break;
            }
            default:
                cout << "Invalid choice" << endl;
        }
    
    }while(choice != 6);
    
    return 0;
}

void saveToFile(const LinkedList<Student>& studentList, const string& filename){
    ofstream outFile(filename);
    if(!outFile){
        cout << "Error: couldn't open the file...." << endl;
        return;
    }
    for(int i = 1; i <= studentList.getLength(); i++){
        outFile << studentList.getEntry(i).toFileString() << endl;
    }
    outFile.close();
    cout << "Data Saved to " << filename << ".\n";
}

void loadFromFile(LinkedList<Student>& studentList, const string& filename){
    ifstream inFile(filename);
    if(!inFile){
        cout << "No record found in " << filename << endl;
        return;
    }
    string line;
    while(getline(inFile, line)){
        Student s;
        s.fromFileString(line);
        studentList.insert(studentList.getLength() + 1, s);
    }
    inFile.close();
    cout << "Loaded data from " << filename << ".\n";
}