#include <iostream>
using namespace std;

int main()
{
    // Declare and initialize integer array of size 5
    int numbers[5] = {10, 20, 30, 40, 50};

    // Display array elements using loop
    cout << "Array Elements are:\n";

    for (int i = 0; i < 5; i++)
    {
        // Print each element of array
        cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }

    return 0;
}
