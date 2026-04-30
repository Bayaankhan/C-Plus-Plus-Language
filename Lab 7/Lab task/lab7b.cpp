#include <iostream>
using namespace std;

int main()
{
    // Declare character array to store a word
    char message[] = "HELLO";

    // Display each character on separate line
    cout << "Characters of the word are:\n";

    for (int i = 0; message[i] != '\0'; i++)
    {
        // Print each character until null character
        cout << message[i] << endl;
    }

    return 0;
}
