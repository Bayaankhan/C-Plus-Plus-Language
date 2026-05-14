#include <iostream>
#include <cstring>   // strlen() ke liye
using namespace std;

int main()
{
    char message[] = "Welcome to C++ Programming";

    cout << "String is: " << message << endl;

    // strlen() string ki length nikalta hai
    cout << "Length of string is: " << strlen(message) << endl;

    return 0;
}
