#include <iostream>
using namespace std;

int main()
{
    // 3x3 array declare aur initialize
    int matrix[3][3] = {
        {2, 4, 6},
        {1, 3, 5},
        {7, 8, 9}
    };

    int totalSum = 0;

    // Rows ka sum nikalna
    cout << "Rows ka sum:\n";

    for (int i = 0; i < 3; i++)
    {
        int rowSum = 0;

        for (int j = 0; j < 3; j++)
        {
            rowSum = rowSum + matrix[i][j];
            totalSum = totalSum + matrix[i][j];
        }

        cout << "Row " << i + 1 << " ka sum = " << rowSum << endl;
    }

    cout << endl;

    // Columns ka sum nikalna
    cout << "Columns ka sum:\n";

    for (int j = 0; j < 3; j++)
    {
        int colSum = 0;

        for (int i = 0; i < 3; i++)
        {
            colSum = colSum + matrix[i][j];
        }

        cout << "Column " << j + 1 << " ka sum = " << colSum << endl;
    }

    cout << endl;

    // Total sum display karna
    cout << "Tamam elements ka total sum = " << totalSum << endl;

    return 0;
}
