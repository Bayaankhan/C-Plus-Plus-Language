#include <iostream>
using namespace std;

// function prototype
int calculateSum(int arr[], int size);

int main() {
    int arr[10];
    int sum;
    float avg;

    // input lena
    cout << "Enter 10 numbers:\n";
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    // function call
    sum = calculateSum(arr, 10);

    // average calculate
    avg = sum / 10.0;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << avg << endl;

    return 0;
}

// function definition
int calculateSum(int arr[], int size) {
    int sum = 0;

    for(int i = 0; i < size; i++) {
        sum += arr[i]; // har element add ho raha hai
    }

    return sum;
}
