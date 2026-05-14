#include <iostream>
using namespace std;

int main()
{
    // array declare ki
    int numbers[] = {10, 20, 30, 40, 50};

    // pointer declare kiya
    int *ptr;

    // pointer ko array ke first element per point kiya
    ptr = numbers;

    // pointer arithmetic se array print
    cout << "Array elements are:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << *(ptr + i) << endl;
    }

    return 0;
}
