#include <iostream>
using namespace std;

// function prototype
void multiply(int num1, int num2);

int main() {
    multiply(5, 4); // function call
    return 0;
}

void multiply(int num1, int num2) {
    int result = num1 * num2;

    // result print karna
    cout << "Multiplication = " << result << endl;
}
