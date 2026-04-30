#include <iostream>
using namespace std;

int main()
{
    // 3x3 ka 2D array declare aur initialize kar rahe hain
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matrix ke elements hain:\n";

    // Nested loop se matrix ke tamam elements display karenge
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Har element print karna
            cout << matrix[i][j] << " ";
        }

        // Har row ke baad next line
        cout << endl;
    }

    return 0;
}
