#include <iostream>
using namespace std;

int main()
{
    // Declare array for 5 numbers
    int numbers[5];
    int sum = 0;

    // Take input from user
    cout << "Enter 5 numbers:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> numbers[i];

        // Add each number to sum
        sum = sum + numbers[i];
    }

    // Display total sum
    cout << "Sum of all numbers = " << sum << endl;

    return 0;
}
