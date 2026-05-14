#include <iostream>
#include <string>
using namespace std;

// Roman Urdu: Student structure banaya
struct Student
{
    string name;
    int age;
    char grade;
};

int main()
{
    // structure variable banaya
    Student student1;

    //  values assign ki
    student1.name = "Muhammad Yaseen";
    student1.age = 20;
    student1.grade = 'A';

    //  values display ki
    cout << "Student Information" << endl;
    cout << "Name: " << student1.name << endl;
    cout << "Age: " << student1.age << endl;
    cout << "Grade: " << student1.grade << endl;

    return 0;
}
