#ifndef PROJECT_BOOK_H
#define PROJECT_BOOK_H
#include "LinkedList.h"
#include "Copies.h"
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

class Book {
private:
    string BookName;
    int ISBN;
    int NumberOfCopies;
public:
    queue<Copies>copies;
    Book(const string &bookName, int isbn, int numberOfCopies, const queue<Copies> &copis) {
        BookName=(bookName);
        ISBN=(isbn);
        NumberOfCopies=(numberOfCopies);
        copies=(copis);
    }

    Book():BookName(""),ISBN(0),NumberOfCopies(0){}

    void setBookName(const string &bookName) {
        BookName = bookName;
    }

    int getNumberOfCopies() const {
        return NumberOfCopies;
    }

    void setNumberOfCopies(int numberOfCopies) {
        NumberOfCopies = numberOfCopies;
    }

    bool operator==(const Book &rhs) const {
        return BookName == rhs.BookName;
    }

    bool operator!=(const Book &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const Book &book) {
        os << "BookName: " << book.BookName << "\nISBN: " << book.ISBN << "\nNumberOfCopies: " << book.NumberOfCopies
           << "\n";
        queue<Copies> temp=book.copies;
        for(int i=0;i<book.NumberOfCopies;i++) {
            cout << temp.front();
            temp.pop();
        }
        return os;
    }

    friend istream &operator>>(istream &in, Book &book){
        cout<<"Enter Book Name: "; in>>book.BookName;
        cout<<"Enter ISBN: "; in>>book.ISBN;
        return in;
    }
};


#endif