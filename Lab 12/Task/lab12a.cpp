#include <iostream>
using namespace std;

int main()
{
    // integer variable declare ki aur value di
    int num = 25;

    // integer pointer declare kiya
    int *ptr;

    // pointer ko num ka address diya
    ptr = &num;

    // original value print
    cout << "Value of num: " << num << endl;

    // pointer ke through value print
    cout << "Value pointed by ptr: " << *ptr << endl;

    return 0;
}
