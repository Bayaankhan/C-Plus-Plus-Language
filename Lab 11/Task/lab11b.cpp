#include <iostream>
#include <cstring>   // strcat() ke liye
using namespace std;

int main()
{
    char firstName[50] = "Muhammad ";
    char lastName[50] = "Yaseen";

    // lastName ko firstName ke end me jorna
    strcat(firstName, lastName);

    cout << "Full Name is: " << firstName << endl;

    return 0;
}
