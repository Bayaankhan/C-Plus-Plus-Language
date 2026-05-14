#include <iostream>
#include <string>
using namespace std;

// Book structure banaya
struct Book
{
    string title;
    string author;
    float price;
    int pages;
};

int main()
{
    // do structure variables banaye
    Book book1, book2;

    //  book1 ki values
    book1.title = "C++ Programming";
    book1.author = "Bjarne";
    book1.price = 1200.50;
    book1.pages = 450;

    //  book2 ki values
    book2.title = "Data Structures";
    book2.author = "Mark Allen";
    book2.price = 950.75;
    book2.pages = 300;

    //  book1 ki information
    cout << "Book 1 Information" << endl;
    cout << "Title: " << book1.title << endl;
    cout << "Author: " << book1.author << endl;
    cout << "Price: " << book1.price << endl;
    cout << "Pages: " << book1.pages << endl;

    cout << endl;

    //  book2 ki information
    cout << "Book 2 Information" << endl;
    cout << "Title: " << book2.title << endl;
    cout << "Author: " << book2.author << endl;
    cout << "Price: " << book2.price << endl;
    cout << "Pages: " << book2.pages << endl;

    return 0;
}
