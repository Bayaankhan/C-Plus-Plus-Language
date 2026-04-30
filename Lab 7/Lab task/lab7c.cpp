#include <iostream>
using namespace std;

int main()
{
    // Declare source and destination arrays
    int source[5] = {5, 10, 15, 20, 25};
    int destination[5];

    // Copy elements from source to destination
    for (int i = 0; i < 5; i++)
    {
        destination[i] = source[i];
    }

    // Display source array
    cout << "Source Array:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << source[i] << " ";
    }

    cout << endl;

    // Display destination array
    cout << "Destination Array:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << destination[i] << " ";
    }

    return 0;
}
