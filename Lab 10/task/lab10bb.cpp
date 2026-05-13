#include <iostream>
using namespace std;

// function prototype
int getSquare(int number);

int main() {
    int num, square;

    cout << "Enter a number: ";
    cin >> num;

    // function call
    square = getSquare(num);

    cout << "Square = " << square << endl;

    return 0;
}

int getSquare(int number) {
    return number * number; // square return kar raha hai
}
