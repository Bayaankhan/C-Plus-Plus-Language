#include <iostream>
#include <string>
using namespace std;

// Roman Urdu: Person naam ka structure banaya
struct Person
{
    string name;
    int age;
    string address;
};

int main()
{
    // structure variable banaya
    Person person1;

    // Roman Urdu: values assign ki
    person1.name = "Muhammad Yaseen";
    person1.age = 20;
    person1.address = "Peshawar";

    //  structure members print kiye
    cout << "Person Information" << endl;
    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "Address: " << person1.address << endl;

    return 0;
}
