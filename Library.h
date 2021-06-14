#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H
#include "LinkedList.h"
#include "Book.h"
#include "Copies.h"
#include <bits/stdc++.h>
using namespace std;

class Library {
private:
    LinkedList<Book> books;
public:
    Library() {
        mainMenu();
    }

    void addNewBook() {
        Book temp;
        cout << "You are Now Inserting new book;-\n";
        cin >> temp;
        books.insert(temp);
    }

    void addNewCopy() {
        Copies temp;
        Book t;
        string name;
        cout << "Enter Book Name: ";
        cin >> name;
        t.setBookName(name);
        cin >> temp;
        if (books.search(t) == nullptr)
            return;
        t = books.search(t)->getVal();
        t.copies.push(temp);
        t.setNumberOfCopies((t.getNumberOfCopies()) + 1);
        books.search(t)->setVal(t);
    }

    void borrowBook() {
        string BookName, BorrowerName, BorrowDate;
        bool done = false;
        Book t;
        cout << "Enter Book Name: ";
        cin >> BookName;
        cout << "Enter Your Name: ";
        cin >> BorrowerName;
        cout << "Enter Today's Date: ";
        cin >> BorrowDate;
        t.setBookName(BookName);
        if (books.search(t) == nullptr)
            return;
        t = books.search(t)->getVal();
        queue<Copies> temp;
        for (int i = 0; i < t.getNumberOfCopies(); i++) {
            if (t.copies.front().isAvailable()) {
                done = true;
                t.copies.front().setAvailable(false);
                t.copies.front().setBorrowDate(BorrowDate);
                t.copies.front().setBorrower(BorrowerName);
                t.copies.front().setReturnDays(15);;
                for (; i < t.getNumberOfCopies(); i++) {
                    temp.push(t.copies.front());
                    t.copies.pop();
                }
                t.copies = temp;
                break;
            }
            temp.push(t.copies.front());
            t.copies.pop();
        }
        books.search(t)->setVal(t);
        if (!done)
            cout << "Unfortunately there is no available Copies for you to borrow.\n";
    }

    void returnBook() {
        string BookName, BorrowerName;
        Book t;
        cout << "Enter Book Name: ";
        cin >> BookName;
        cout << "Enter Your Name: ";
        cin >> BorrowerName;
        t.setBookName(BookName);
        if (books.search(t) == nullptr)
            return;
        t = books.search(t)->getVal();
        queue<Copies> temp;
        for (int i = 0; i < t.getNumberOfCopies(); i++) {
            if (t.copies.front().getBorrower()==BorrowerName) {
                t.copies.front().setAvailable(true);
                t.copies.front().setReturnDays(0);
                t.copies.front().setBorrower("");
                t.copies.front().setBorrowDate("");
                for (; i < t.getNumberOfCopies(); i++) {
                    temp.push(t.copies.front());
                    t.copies.pop();
                }
                t.copies = temp;
                break;
            }
            temp.push(t.copies.front());
            t.copies.pop();
        }
        books.search(t)->setVal(t);
    }

    static char toUpper(char temp) {
        return ((temp >= 'a' && temp <= 'z') ? temp -= 32 : temp);
    }

    void mainMenu() {
        int choice;
repeat:
        cout << "Welcome to Our Library, Please Choose one of the following Options:-\n";
        cout << "1-Adding New Book\n2-Adding Book Copy\n3-Borrow Book\n4-Return Book\n5-Library Inventory\n";
        cin >> choice;
        while (choice < 1 || choice > 5) {
            cout << "Enter Numbers Between 1~5 Only: ";
            cin >> choice;
        }
        switch (choice) {
            case 1:
                addNewBook();
                break;
            case 2:
                addNewCopy();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                LinkedList<Book>::printLL(books.getHead());
                break;
        }
        char ch;
        cout << "Do you want Another Operation(Y/N): ";
        cin >> ch;
        while (toUpper(ch) != 'N' && toUpper(ch) != 'Y') {
            cout << "Enter Only Y or N: ";
            cin >> ch;
        }
        if (toUpper(ch)=='Y')
            goto repeat;
        cout<<"Thanks For Using Our Library\n";
   }

};


#endif //PROJECT_LIBRARY_H
