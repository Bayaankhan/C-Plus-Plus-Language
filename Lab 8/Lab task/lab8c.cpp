#include <iostream>
using namespace std;

int main()
{
    // 4x4 array declare aur initialize
    int matrix[4][4] = {
        {12, 25, 7, 18},
        {30, 14, 9, 22},
        {5, 17, 40, 11},
        {8, 19, 13, 27}
    };

    // Pehla element maximum maan lete hain
    int max = matrix[0][0];

    // Nested loop se maximum value find karenge
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // Agar current element bara ho to max update karo
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }

    // Maximum value display karna
    cout << "Matrix ki maximum value = " << max << endl;

    return 0;
}
